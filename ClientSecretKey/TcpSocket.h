#pragma once
#include<iostream>
using namespace std;
static const int TIMEOUT = 10000;
class TcpSocket
{

public:
	enum ErrorType
	{
		ParamError = 3001,
		TimeoutError,
		PeerCloseError,
		MallocError
	};
	TcpSocket();
	TcpSocket(int socket);
	~TcpSocket();

	int connectToHost(string ip, unsigned short port, int timeout = TIMEOUT);
	int sendMessage(string data, int timeout = TIMEOUT);
	string recvMessage(int timeout = TIMEOUT);
	void disConnect();

private:
	int setNonBlock(int fd);
	int setBlock(int fd);
	int readTimeout(unsigned int wait_time);//返回0没超时 -1超时 同writeTimeout()
	int writeTimeout(unsigned int wait_time);
	int connectTimeout(struct sockaddr_in* addr, unsigned int wait_time);
	int readn(void* buf, int count);
	int writen(const void* buf, int count);
private:
	int m_socket;

};

