﻿#include <stdio.h>
#include <unistd.h>
#include "Server.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("./a.out port path\n");
        return -1;
    }

    unsigned short port = atoi(argv[1]);  //atoi 将字符串转为整型

    chdir(argv[2]);  // 切换服务器的工作路径(路径切换到用户输入的路径)

    //初始化用于监听的套接字
    int lfd = initListenFd(port);

    //启动服务器程序（epoll方式）
    epollRun(lfd);

    return 0;
}