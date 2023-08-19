#pragma once

#include "mprpcconfig.h"

void MprpcConfig::Trim(std::string &str)
{
    //去掉前面的空格
    int idx = str.find_first_not_of(' ');
    str = str.substr(idx, str.size()-idx);
    //去掉后面的空格
    idx = str.find_last_not_of(' ');
    str = str.substr(0, idx+1);
}

void MprpcConfig::LoadConfigFile(std::string filename)
{
    FILE *fp = fopen(filename.c_str(), "r");

    //1. 注释   2.前后的空格    3.正确输入的键值对 = 
    //逐行读取文件内容
    while(!feof(fp))
    {
        char buf[512];
        fgets(buf, 512, fp);

        std::string str_buf(buf);
        //去掉前后的空格
        Trim(str_buf);

        //跳过注释行
        if(str_buf[0] == '#' || str_buf.empty())
        {
            continue;
        }

        //提取 (key,value) 对
        int idx = str_buf.find('=');
        if(idx == -1)
        {
            //配置项不合法
            continue;
        }

        std::string key = str_buf.substr(0, idx);
        //去掉“-”前的空格，避免 "rpcserverip   "
        Trim(key);

        //去掉等号后的换行和空格，避免 "  127.0.0.1    \n"
        int endidx = str_buf.find('\n',idx+1);
        std::string value = str_buf.substr(idx+1, endidx-idx-1);
        Trim(value);
        
        //存入 _configmap 中，进行复用，避免以后多次读取文件
        _config_map.insert({key, value});
    }
}

std::string MprpcConfig::Load(std::string key)
{
    auto it = _config_map.find(key);
    if(it == _config_map.end())
    {
        return "";
    }
    return it->second;
}