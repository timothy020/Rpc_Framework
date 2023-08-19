#pragma once

#include <string> 
#include <unordered_map>

class MprpcConfig
{
public:
    void LoadConfigFile(std::string filename);
    std::string Load(std::string key);
private:
    //去掉字符串前后的空格
    void Trim(std::string &str);
    std::unordered_map<std::string, std::string> _config_map;
};