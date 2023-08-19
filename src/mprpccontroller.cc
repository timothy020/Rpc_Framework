#include "mprpccontroller.h"
#include <string>

MyRpcController::MyRpcController()
{
    m_failed = false;
    m_errTest = "";
}
bool MyRpcController::Failed() const
{
    return m_failed;
}
void MyRpcController::SetFailed(const std::string& reason)
{
    m_failed = true;
    m_errTest = reason;
}
void MyRpcController::Reset()
{
    m_failed = false;
    m_errTest = "";
}
std::string MyRpcController::ErrorText() const
{
    return m_errTest;
}

//目前未实现的功能
void MyRpcController::StartCancel() {}
bool MyRpcController::IsCanceled() const {}
void MyRpcController::NotifyOnCancel(google::protobuf::Closure* callback) {}