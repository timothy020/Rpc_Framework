#include<iostream>
#include<string>
#include"mprpcapplication.h"
#include"user.pb.h"

/*
UserService原本是一个本地服务，提供了两个进程内的本地方法，Login和GetFriendList
*/
class UserServer : public fixbug::UserService
{
public:
    bool Login(std::string name, std::string pwd){ //使用在Rpc服务端 (Rpc服务提供者)
        std::cout<< "doing loacl service" << std::endl;
        std::cout<< "name: " << name << " pwd: " << pwd << std::endl;
        return true;
    }
    
    /*
    重写基类UserService的虚函数 下面这些方法都是由框架直接调用
    1. caller => Login(LoginRequest) => muduo => callee
    2. callee => 辨别出Login(LoginRequest) => 交给下面的函数处理
    */
    void login(google::protobuf::RpcController* controller,
                       const fixbug::LoginRequest* request,
                       fixbug::LoginResponse* response,
                       google::protobuf::Closure* done)
    {
        //框架给业务上报了请求参数LoginRequest， 应用获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd  = request->pwd();
     
        //做本地业务
        bool res = Login(name,pwd);

        //把响应写入 包括返回值，错误码，错误消息
        fixbug::ResultCode *rcode =  response->mutable_rcode();
        rcode->set_errnum(0);
        rcode->set_errmsg("");
        response->set_success(res);

        //执行回调操作 执行响应对象数据序列化和网络发送（由框架完成）
        done->Run();
    }

};



int main(int argc, char **argv)
{
    //调用框架的初始化操作
    MprpcApplication::Init(argc, argv);    

    //provider是一个rpc网络服务对象，把UserService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new UserServer());

    //启动一个rpc服务节点 Run以后，进程进入阻塞状态，等待远程rpc调用请求
    provider.Run();

    return 0;
}