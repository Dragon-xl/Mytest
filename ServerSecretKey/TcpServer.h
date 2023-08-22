#pragma once
#include"TcpSocket.h"
class TcpServer
{
public:
	TcpServer();
	~TcpServer();
	int setListen(unsigned short port);
	TcpSocket* acceptConnect(int timeout = 10000);
	void closefd();
private:
	int m_lfd;
};

