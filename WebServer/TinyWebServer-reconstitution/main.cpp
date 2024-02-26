#include "config.h"

int main(int argc, char *argv[])
{
    //需要修改的数据库信息,登录名,密码,库名
    string user = "root";
    string passwd = "root";
    string databasename = "yourdb";

    //命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    //初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    
    cout << "初始化over" << endl;
    //日志
    server.log_write();
    cout << "日志over" << endl;
    //数据库
    server.sql_pool();
    cout << "数据库over" << endl;
    //线程池
    server.thread_pool();
    cout << "线程池over" << endl;
    //触发模式
    server.trig_mode();
    cout << "触发模式over" << endl;
    //监听
    server.eventListen();
    cout << "监听over" << endl;
    //运行
    server.eventLoop();
    cout << "运行over" << endl;
    return 0;
}
