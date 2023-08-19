#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"

int main(int argc, char **argv)
{
    //整个程序启动以后，想使用mprpc来享受rpc服务调用，一定要先调用框架的初始化函数（只初始化一次）
    MprpcApplication::Init(argc, argv);

    //演示调用远程发布的rpc方法 Login
    fixbug::UserService_Stub stub(new MprpcChannel());

    // rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    // rpc方法的响应
    fixbug::LoginResponse response;
    // 发起rpc方法调用 同步的rpc调用过程 MrpcChannel::CallMethod
    stub.login(nullptr, &request, &response, nullptr); //RpcChannel->RpcChannel::CallMethod 集中来做所有的rpc方法的参数序列化和网络发送

    //一次rpc调用完成，读调用的结果
    if(response.rcode().errnum() == 0)
    {
        std::cout<< "rpc login response: " << response.success()<< std::endl;
    }
    else
    {
        std::cout<< "rpc login response err: "<<response.rcode().errmsg() <<" " << 
            " errnum: "<< response.rcode().errnum() <<" success: " << response.success()<< std::endl;
    }

    return 0;
}