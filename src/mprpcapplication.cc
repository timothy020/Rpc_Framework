#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include "logger.h"

//静态变量需要在类外初始化
MprpcConfig MprpcApplication::_mprpcconfig;

void ShowArgHelp()
{
    std::cout<< "format: command -i <configfile>" <<std::endl;
}

void MprpcApplication::Init(int argc, char **argv)
{
    if(argc < 2)
    {
        ShowArgHelp();
        exit(EXIT_FAILURE);
    }

    //解析命令行输入的参数, i: 表示 i 后有参数
    int c = 0;
    std::string config_file;
    while((c = getopt(argc, argv, "i:")) != -1)
    {
        switch(c)
        {
            case 'i':
                config_file = optarg;
                break;
            //没找到 -i
            case '?':
                ShowArgHelp();
                exit(EXIT_FAILURE);
            //找到了 -i但是没有参数
            case ':':
                ShowArgHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }

    //开始加载配置文件 rpcserverip= rpcserverport= zookeeperip= zookeeperport=
    _mprpcconfig.LoadConfigFile(config_file);

    std::cout<< "rpcserverip: " << _mprpcconfig.Load("rpcserverip") << std::endl;
    std::cout<< "rpcserverport: " << _mprpcconfig.Load("rpcserverport") << std::endl;
    std::cout<< "zookeeperip: " << _mprpcconfig.Load("zookeeperip") << std::endl;
    std::cout<< "zookeeperport: " << _mprpcconfig.Load("zookeeperport") << std::endl;

}

MprpcApplication& MprpcApplication::GetInstance()
{
    static MprpcApplication app;
    return app;
}
MprpcConfig& MprpcApplication::GetMprpcConfig()
{
    return _mprpcconfig;
}