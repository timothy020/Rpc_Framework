#include "rpcprovider.h"
#include "mprpcapplication.h"
#include <functional>
#include <google/protobuf/descriptor.h>
#include "rpcheader.pb.h"
#include "zookeeperutil.h"

/*
Service_name => Service_Info
                    Service服务对象
                    method_name => Method
*/
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
    ServiceInfo serviceinfo;

    //获取了服务对象的描述信息
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    //获取服务名称
    std::string service_name = pserviceDesc->name();
    //获取服务对象Server的方法的数量
    int methodCnt = pserviceDesc->method_count();

    std::cout<<"service_name: "<<service_name <<std::endl; //输出Service_name

    for(int i = 0; i < methodCnt; ++i)
    {
        //获取服务对象指定下标的服务方法的描述（抽象描述）
        const google::protobuf::MethodDescriptor *pmethodDesc 
            = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();

        std::cout<< "method_name: "<< method_name <<std::endl; //输出 method_name
        serviceinfo.m_methodMap.insert({method_name, pmethodDesc});  //第三层：填充method_name => Method
    }

    serviceinfo.m_service = service;   //第二层：填充Service服务对象
    m_servicemap.insert({service_name, serviceinfo}); //第一层：填充Service_name => Service_Info
}

void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetMprpcConfig().Load("rpcserverip");
    uint16_t port = atoi(MprpcApplication::GetMprpcConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);

    //创建TcpServer对象
    muduo::net::TcpServer m_tcpServer(&m_eventloop, address, "Provider");

    //设置连接和消息读写回调 分离了网络代码和业务代码
    m_tcpServer.setConnectionCallback(std::bind(&RpcProvider::ConnectionCallback, this, std::placeholders::_1));
    m_tcpServer.setMessageCallback(std::bind(&RpcProvider::MessageCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    //设置muduo网络库的线程数量
    m_tcpServer.setThreadNum(4);

    //把当前rpc节点上要发布的服务全部注册到zk上面，让rpc_client可以从zk上发现服务
    ZkClient zkCli;
    zkCli.Start();
    //service_name 为永久性节点， method_name为临时性节点
    for(auto &sp : m_servicemap)
    {
        // /service_name
        std::string service_path = "/" + sp.first;
        zkCli.Creat(service_path.c_str(), nullptr, 0);
        for(auto &mp : sp.second.m_methodMap)
        {
            // /service_name/method_name
            std::string method_path = service_path+"/"+mp.first;
            char method_path_data[128]={0};
            sprintf(method_path_data, "%s:%d", ip.c_str(), port);
            //  ZOO_EPHEMERAL：临时节点
            zkCli.Creat(method_path.c_str(), method_path_data, strlen(method_path_data), ZOO_EPHEMERAL);
        }
    }

    std::cout<<"RpcServer run at Ip: "<<ip<<" Port: "<<port << std::endl;

    //启动 网络服务
    m_tcpServer.start();
    m_eventloop.loop();
}

//新的socket连接回调
void RpcProvider::ConnectionCallback(const muduo::net::TcpConnectionPtr& conn)
{
    if(!conn->connected())
    {
        //和rpc client的连接断开了
        conn->shutdown();
    }
}

/*
在框架内部， RpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型
三要素 service_name method_name args
为了区分出 service_name method_name和 args，定义一个header_size
为了解决Tcp粘包问题，需要记录arg_size

通信格式如下：
header_size(4B) + header + args
    header: service_name method_name args_size
*/

//已建立连接用户的读写事件回调，如果远程有一个rpc服务的调用请求，那么OnMessage方法就会响应
void RpcProvider::MessageCallback(const muduo::net::TcpConnectionPtr& conn,
                                muduo::net::Buffer*buffer ,
                                muduo::Timestamp)
{
    //网络上接受的远程rpc调用请求的字符流 
    std::string recv_buf = buffer->retrieveAllAsString();

    //从字节流中读取前四个字节的内容 header_size
    uint32_t header_size;
    recv_buf.copy((char*)&header_size, 4, 0);

    //反序列化 rpcheader， 得到 service_name, method_name args_size
    std::string service_name;
    std::string method_name;
    uint32_t args_size;

    mprpc::RpcHeader rpcheader;
    if(rpcheader.ParseFromString(recv_buf.substr(4, header_size)))
    {
        //数据头反序列化成功
        service_name = rpcheader.service_name();
        method_name = rpcheader.method_name();
        args_size = rpcheader.args_size();
    }
    else
    {
        //数据头反序列化失败
        std::cout<< "rpr_header_str:" << recv_buf.substr(4, header_size) 
            << "parse err!" << std::endl;
    }
    

    //读取出 args
    std::string args_str = recv_buf.substr(4+header_size, args_size);

    //打印测试结果
    std::cout<<"***************反序列化*******************"<<std::endl;
    std::cout<<"header_size: "  <<header_size<<std::endl;
    std::cout<<"service_name: " <<service_name<<std::endl;
    std::cout<<"moethod_name: " <<method_name<<std::endl;
    std::cout<<"args_size: "    <<args_size<<std::endl;
    std::cout<<"args_str: "         <<args_str<<std::endl;
    std::cout<<"***************反序列化*******************"<<std::endl;

    //获取Service对象和Method对象
    auto it = m_servicemap.find(service_name);
    if(it == m_servicemap.end())
    {
        std::cout<<"service doesn't exist" <<std::endl;
        return;
    }
    auto mit = it->second.m_methodMap.find(method_name);
    if(mit == it->second.m_methodMap.end())
    {
        std::cout<<"method doesn't exist" <<std::endl;
        return;
    }

    google::protobuf::Service *service = it->second.m_service;      //获取Service对象 new UserService
    const google::protobuf::MethodDescriptor *method = mit->second; //获取method方法 Login

    //生成rpc方法调用的请求request和响应response
    google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if(!request->ParseFromString(args_str))
    {
        std::cout<<"Parses from args_str err!"<<std::endl;
        return;
    }    
    google::protobuf::Message *response = service->GetResponsePrototype(method).New();

    //给下面的method方法，绑定一个Closure的回调函数
    google::protobuf::Closure *done = google::protobuf::NewCallback<RpcProvider, 
                                                                    const muduo::net::TcpConnectionPtr&, 
                                                                    google::protobuf::Message*>
                                                                    (this, 
                                                                    &RpcProvider::SendRpcResponse, 
                                                                    conn, response);
    //在框架上根据远端的rpc请求，调用当前rpc节点上发布的方法
    // new UserService().Login(controller, request, response, done)
    service->CallMethod(method,nullptr,request,response,done);
}

//执行玩本地函数后的回调，将Reponse序列化并用网络发送回Rpc Caller
void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* response)
{
    std::string response_str;
    if(response->SerializeToString(&response_str))
    {
        // 序列化成功后，通过网络把rpc方法执行的结果发送会rpc的调用方
        // std::cout<<"SendRpcResponse Serilize success!"<<std::endl;
        // std::cout<<"response_str: "<<response_str<<std::endl;
        
        conn->send(response_str);
    }
    else
    {
        //反序列化失败
        std::cout<< "serialize response_str error!"<<std::endl;
    }
    conn->shutdown(); //模拟httpD短连接
}