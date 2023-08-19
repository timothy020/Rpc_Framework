#pragma once
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <unordered_map>

//框架提供的，专门用来发布rpc服务的网络对象类
class RpcProvider
{
public:
    //这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);
    
    //启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();

private:
    // 因为只有 Run() 用到，所以写到Run() 内部了
    // muduo::net::TcpServer m_tcpServer;
    muduo::net::EventLoop m_eventloop;

    //Service服务类型信息
    struct ServiceInfo
    {
        google::protobuf::Service *m_service; //保存服务对象
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*>
            m_methodMap;  //保存服务方法
    };
    //存储注册成功的服务对象和其服务方法的所有信息
    std::unordered_map<std::string, ServiceInfo> m_servicemap;

    //新的socket连接回调
    void ConnectionCallback(const muduo::net::TcpConnectionPtr&);
    //已建立连接用户的读写事件回调，如果远程有一个rpc服务的调用请求，那么OnMessage方法就会响应
    void MessageCallback(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*, muduo::Timestamp);
    //执行玩本地函数后的回调，将Reponse反序列化并用网络发送回Rpc Caller
    void SendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
};