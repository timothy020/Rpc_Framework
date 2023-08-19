#include "logger.h"
#include <time.h>
#include <iostream>

//获取日志的单例
Logger& Logger::GetInstance()
{
    static Logger logger;
    return logger;
}

Logger::Logger()
{
    //启动专门写日志的线程
    std::thread writetask([&](){
        for(;;)
        {
            //获取当前的日期，然后取日志信息，写入相应的日志文件中 a+
            time_t now = time(nullptr);
            tm *tmtime = localtime(&now);

            char file_name[128];
            sprintf(file_name, "%d-%d-%d-log.txt",tmtime->tm_year+1900,tmtime->tm_mon+1,tmtime->tm_mday);

            //追加文件，不存在则创建
            FILE *fp = fopen(file_name, "a+");
            if(fp == nullptr)
            {
                std::cout<<"logger file : "<<file_name<<" open error!"<<std::endl;
                exit(EXIT_FAILURE);
            }

            //取出缓冲队列里的日志信息
            std::string msg = m_lckQue.pop();
            char time_buf[128] = {0};
            sprintf(time_buf, "%d:%d:%d => [%s]",
                    tmtime->tm_hour,
                    tmtime->tm_min,
                    tmtime->tm_sec,
                    (m_loglevel==INFO ? "info" : "err"));
            msg.insert(0, time_buf);
            msg.append("\n");

            fputs(msg.c_str(), fp);
            fclose(fp);
        }
    });

    //设置线程分离 守护线程
    writetask.detach();

}

//设置日志的级别
void Logger::SetLogLevel(LogLevel level)
{
    m_loglevel = level;
}
//写日志，把日志信息写入lockque缓冲区当中
void Logger::Log(std::string msg)
{
    m_lckQue.push(msg);
}



