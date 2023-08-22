#include "TcpServer.h"
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <string.h>
using namespace std;
TcpServer::TcpServer()
{
}

TcpServer::~TcpServer()
{
}

int TcpServer::setListen(unsigned short port)
{
	int ret = 0;
	m_lfd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_lfd < 0)
	{
		ret = errno;
		return ret;
	}
	int opt = 1;
	 ret = setsockopt(m_lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if (ret == -1)
	{
		return ret = errno;
	}
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	
	socklen_t len = sizeof(addr);
	 ret = bind(m_lfd, (struct sockaddr*)&addr, len);
	if (ret == -1)
	{
		return ret = errno;
	}
	 ret = listen(m_lfd, 128);
	if (ret == -1)
	{
		return ret = errno;
	}
	return ret;


}

TcpSocket* TcpServer::acceptConnect(int wait_time)
{
	cout << m_lfd << endl;
	int ret = 0;
	if (wait_time > 0)
	{
		fd_set read_set;
		FD_ZERO(&read_set);
		FD_SET(m_lfd, &read_set);
		struct timeval timeout;
		timeout.tv_sec = wait_time;
		timeout.tv_usec = 0;
		do
		{
			ret = select(m_lfd + 1, &read_set, NULL, NULL, &timeout);
			cout << ret<< endl;
		} while (ret < 0 && errno == EINTR);
		if (ret <= 0)
		{
			return NULL;
		}
	}
		struct sockaddr_in conaddr;
		socklen_t conlen = sizeof(conaddr);
		int confd = accept(m_lfd, (struct sockaddr*)&conaddr, &conlen);
		if (confd == -1)
		{
			cout << "accept failed" << endl;
			return NULL;
		}
		return new TcpSocket(confd);


	
}

void TcpServer::closefd()
{
	close(m_lfd);
}

