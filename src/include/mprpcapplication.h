# pragma once

#include "mprpcconfig.h"
#include "rpcprovider.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"


//mprpc框架的基础类，负责框架的初始化操作
class MprpcApplication
{
public:
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance();
    static MprpcConfig& GetMprpcConfig();
private:
    static MprpcConfig _mprpcconfig;
    MprpcApplication(){};
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication &&) = delete;
};