#include <google/protobuf/service.h>
#include <string>

class MyRpcController : public google::protobuf::RpcController
{
public:
    MyRpcController();
    bool Failed() const;
    void SetFailed(const std::string& reason);
    void Reset();
    std::string ErrorText() const;

    //目前未实现的功能
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure* callback);
private:
    bool m_failed;          //RPC方法执行时的状态
    std::string m_errTest;  //RPC方法执行过程中的信息
};