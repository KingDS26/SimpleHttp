#pragma once

// ��ʼ�����ڼ������׽���
int initListenFd(unsigned short port);

// �������������� ����epoll
int epollRun(int lfd);

// �Ϳͻ��˽������ӵĺ���
//int acceptClient(int lfd, int epfd);
void* acceptClient(void* arg);

// ����http����
//int recvHttpRequest(int cfd, int epfd);
void* recvHttpRequest(void* arg);

// ����������
int parseRequestLine(const char* line, int cfd);

// �����ļ�(httpЭ��ĵ��Ĳ���)
int sendFile(const char* fileName, int cfd);

// ������Ӧͷ(httpЭ��ĵ�һ�ڶ����֣�״̬��+��Ӧͷ)
int sendHeadMsg(int cfd, int status, const char* descr, const char* type, int length);

// �����ļ���׺�����õ���Ӧ��contenttype �����ߺ�����
const char* getFileType(const char* name);

// ����Ŀ¼
int sendDir(const char* dirName, int cfd);

// ���ַ�ת��Ϊ��������16����ת10���ƣ�
int hexToDec(char c);

// ����
// to �洢����֮������ݣ�����������from ����������ݣ��������
void decodeMsg(char* to, char* from);
