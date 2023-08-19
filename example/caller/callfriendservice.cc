#include <iostream>
#include "mprpcapplication.h"
#include "friendlist.pb.h"

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);

    fixbug::GetFriendListService_Stub stub(new MprpcChannel());

    fixbug::GetFriendListRequest request;
    request.set_id(2222);

    fixbug::GetFriendListResponse response;

    //远程调用rpc方法
    MyRpcController controller;
    stub.GetFriendList(&controller, &request, &response, nullptr);

    if(controller.Failed())
    {
        //rpc远程调用时发生错误
        std::cout<<"GetFriendList Rpc Call error! reason: "
            << controller.ErrorText() << std::endl;
    }
    else
    {
        //rpc远程调用成功
        uint32_t errnum = response.mutable_rcode()->errnum();
        std::string errmsg = response.mutable_rcode()->errmsg();
        std::cout<<"errnum: "<<errnum<<" errmsg: "<<errmsg<<std::endl;

        for(int i = 0; i <response.names_size(); ++i)
        {
            std::cout<<"friend name: "<<response.names(i)<<std::endl;
        } 
    }
    
    return 0;
}