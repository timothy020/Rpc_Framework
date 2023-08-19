#include <iostream>
#include "mprpcapplication.h"
#include "friendlist.pb.h"
#include <vector>
#include "logger.h"

class GetFriendListService : public fixbug::GetFriendListService
{
public:
    std::vector<std::string> GetFriendList(uint32_t id)
    {
        std::vector<std::string> res;
        std::cout<<"doing local Service! id="<<id<<std::endl;
        res.push_back("zhang san");
        res.push_back("li si");
        res.push_back("wang wu");
        return res;
    }

    void GetFriendList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendListRequest* request,
                       ::fixbug::GetFriendListResponse* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t id = request->id();
        std::vector<std::string> names_vec = GetFriendList(id);

        response->mutable_rcode()->set_errnum(1);
        response->mutable_rcode()->set_errmsg("text errmsg");
        for(std::string &s : names_vec)
        {
            response->add_names(s);
        }

        done->Run();
    }
};

int main(int argc, char **argv)
{
    LOG_INFO("first message!");
    LOG_ERR("fitst error message! %s:%s:%d", __FILE__,__FUNCTION__,__LINE__);

    MprpcApplication::Init(argc, argv);

    RpcProvider provider;
    provider.NotifyService(new GetFriendListService());

    provider.Run();

    return 0;
}