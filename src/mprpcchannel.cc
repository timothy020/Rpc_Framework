#include "mprpcchannel.h"
#include <string>
#include "rpcheader.pb.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include "mprpcapplication.h"
#include "zookeeperutil.h"

/*
header_size + service_name method_name arg_size + args
*/
//所有通过stub代理对象调用的方法，都走到这里了，统一做rpc方法调用的数据序列化和网络发送
void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                                google::protobuf::RpcController* controller, 
                                const google::protobuf::Message* request,
                                google::protobuf::Message* response,
                                google::protobuf:: Closure* done)
{
    const google::protobuf::ServiceDescriptor* service = method->service();
    std::string service_name = service->name();  //service_name
    std::string method_name  = method->name();   //method_name

    std::string args_str;
    uint32_t args_size;
    if(request->SerializeToString(&args_str))
    {
        //序列化成功
        args_size = args_str.size();
    }
    else
    {
        //序列化失败
        controller->SetFailed("serialize request in MprpcChannel::CallMethod err!");
        return;
    }
    
    mprpc::RpcHeader rpcheader;
    rpcheader.set_service_name(service_name);
    rpcheader.set_method_name(method_name);
    rpcheader.set_args_size(args_size);

    std::string header_str;
    uint32_t header_size;
    if(rpcheader.SerializeToString(&header_str))
    {
        header_size = header_str.size();
    }
    else
    {
        controller->SetFailed("serialize header in MprpcChannel::CallMethod err!");
        return;
    }

    std::string send_str;
    send_str.insert(0, std::string((char*)&header_size,4)); //send_str内存写
    send_str += header_str + args_str;
    
    //打印测试结果
    std::cout<<"***************序列化*******************"<<std::endl;
    std::cout<<"header_size: "  <<header_size<<std::endl;
    std::cout<<"service_name: " <<service_name<<std::endl;
    std::cout<<"moethod_name: " <<method_name<<std::endl;
    std::cout<<"args_size: "    <<args_size<<std::endl;
    std::cout<<"args_str: "         <<args_str<<std::endl;
    std::cout<<"***************序列化*******************"<<std::endl;

    // 使用tcp编程，完成rpc方法的远程调用
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == clientfd)
    {
        std::string err_str = "create socket error! errno: ";
        err_str += errno;
        controller->SetFailed(err_str);
        close(clientfd);
        return;
    }

    //读取配置未见rpcserver配置信息
    // std::string ip = MprpcApplication::GetInstance().GetMprpcConfig().Load("rpcserverip");
    // uint16_t port = atoi(MprpcApplication::GetInstance().GetMprpcConfig().Load("rpcserverport").c_str());
    // rpc调用方法想调用service_name的method_name方法，需要查询zk上该服务所在的host信息
    ZkClient zkCli;
    zkCli.Start();
    // /UserService/login
    std::string method_path = "/"+service_name+"/"+method_name;
    // 127.0.0.1:8000
    std::string host_data = zkCli.GetData(method_path.c_str());
    if(host_data == "" )
    {
        controller->SetFailed(method_path+" is not exist!");
        return;
    }
    int idx = host_data.find(":");
    if(idx==-1)
    {
        controller->SetFailed(method_path+" address is not valid!");
        return;
    }
    std::string ip = host_data.substr(0,idx);
    uint16_t port = atoi(host_data.substr(idx+1,host_data.size()-idx).c_str());


    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    server_addr.sin_port = htons(port);
    
    //连接rpc服务节点
    if( -1 == connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr)))
    {
        std::string err_str = "connect socket error! errno: ";
        err_str += errno;
        controller->SetFailed(err_str);
        close(clientfd);
        return;
    }

    //发送rpc请求
    if(-1 == send(clientfd, send_str.c_str(), send_str.size(), 0))
    {
        std::string err_str = "send socket error! errno: ";
        err_str += errno;
        controller->SetFailed(err_str);
        close(clientfd);
        return;
    }

    //接收rpc请求的响应值
    char recv_buf[1024]={0};
    int recv_size = 0;
    if(-1 == (recv_size = recv(clientfd, recv_buf, 1024, 0)))
    {
        std::string err_str = "recv socket error! errno: ";
        err_str += errno;
        controller->SetFailed(err_str);
        close(clientfd);
        return;
    }

    // std::string response_str(recv_buf,0,recv_size); //Bug: 构造函数构造时遇到 /0自动终止
    // if(!response->ParseFromString(response_str))
    if(!response->ParseFromArray(recv_buf, recv_size))
    {
        std::string err_str = "parse socket error! response_str: ";
        err_str += recv_buf;
        controller->SetFailed(err_str);
        close(clientfd);
        return;
    }
    close(clientfd);
}