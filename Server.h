#pragma once

// 初始化用于监听的套接字
int initListenFd(unsigned short port);

// 启动服务器程序 启动epoll
int epollRun(int lfd);

// 和客户端建立连接的函数
//int acceptClient(int lfd, int epfd);
void* acceptClient(void* arg);

// 接收http请求
//int recvHttpRequest(int cfd, int epfd);
void* recvHttpRequest(void* arg);

// 解析请求行
int parseRequestLine(const char* line, int cfd);

// 发送文件(http协议的第四部分)
int sendFile(const char* fileName, int cfd);

// 发送响应头(http协议的第一第二部分：状态行+响应头)
int sendHeadMsg(int cfd, int status, const char* descr, const char* type, int length);

// 根据文件后缀名，得到相应的contenttype （工具函数）
const char* getFileType(const char* name);

// 发送目录
int sendDir(const char* dirName, int cfd);

// 将字符转换为整型数（16进制转10进制）
int hexToDec(char c);

// 解码
// to 存储解码之后的数据，传出参数；from 被解码的数据，传入参数
void decodeMsg(char* to, char* from);
