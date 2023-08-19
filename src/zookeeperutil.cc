#include "zookeeperutil.h"
#include "mprpcapplication.h"
#include "semaphore.h"
#include <iostream>

ZkClient::ZkClient() : m_zhandle(nullptr)
{
}

ZkClient::~ZkClient()
{
    if(m_zhandle != nullptr)
    {
        zookeeper_close(m_zhandle);  //关闭句柄，释放连接 MySQL_Conn
    }
}

// 全局的watcher回调句柄
void global_watcher(zhandle_t *zh, int type, 
        int state, const char *path,void *watcherCtx)
{
    if(type == ZOO_SESSION_EVENT)   //回调的消息类型是和会话相关的消息类型
    {
        if(state == ZOO_CONNECTED_STATE)    // zkClient和zkServer连接成功
        {
            sem_t *sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}

// 连接zkserver
void ZkClient::Start()
{
    std::string host = MprpcApplication::GetInstance().GetMprpcConfig().Load("zookeeperip");
    std::string port = MprpcApplication::GetInstance().GetMprpcConfig().Load("zookeeperport");
    std::string connstr = host+":"+port;

    /*
    zookeeper_mt：多线程版本
    zookeeper的API客户端提供了三个线程
    API调用线程
    网络IO线程      pthread_create poll
    watcher回调线程
    */
    m_zhandle = zookeeper_init(connstr.c_str(),global_watcher,3000,nullptr,nullptr,0);
    if(nullptr == m_zhandle)
    {
        std::cout << "zookeeper_init error!"<<std::endl;
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(m_zhandle,&sem);

    sem_wait(&sem);
    std::cout<<"zookeeper_init success!"<<std::endl;
}

// 在zkserver上根据指定的path创建znod节点
void ZkClient::Creat(const char*path, const char *data, int datalen, int state)
{
    char path_buffer[128];
    int bufferlen = sizeof(path_buffer);
    int flag;
    //先判断path表示的znode节点是否存在，如果存在就不再重复创建了
    flag = zoo_exists(m_zhandle, path, 0, nullptr);
    if(ZNONODE == flag) // 表示path的znode节点不存在
    {
        //创建指定的path的znode节点
        flag = zoo_create(m_zhandle, path, data, datalen,
            &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen); //后两个参数没什么用
        if(ZOK == flag)
        {
            std::cout<<"znode create success... path: "<<path<<std::endl; 
        }
        else
        {
            std::cout<<"flag: "<<flag <<std::endl;
            std::cout<<"znode create error... path:"<<path<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

// 根据参数指定的znode节点路径，获取znode节点的值
std::string ZkClient::GetData(const char* path)
{
    char buffer[64];
    int buffer_len = sizeof(buffer);
    int flag;
    flag = zoo_get(m_zhandle, path, 0, buffer, &buffer_len, nullptr);
    if(flag != ZOK)
    {
        std::cout<<"get znode error... path: "<<path<<std::endl;
        return "";
    }
    else
    {
        return buffer;
    }
}