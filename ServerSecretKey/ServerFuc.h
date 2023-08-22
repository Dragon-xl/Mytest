#pragma once
#include<string>
#include<map>
#include"TcpSocket.h"
#include"Message.pb.h"
#include"TcpServer.h"
#include"OCCIFuc.h"
#include"SecretKeyShm.h"
using namespace std;
class ServerFuc
{

public:
	enum randKeyLen
	{
		Len16=16,
		Len24=24,
		Len32=32
	};
	ServerFuc(string json);
	~ServerFuc();
	void startServer();
	static void* work(void* arg);
	string  KeyAgreement(ResquestMsg* reqmsg);
private:
	string randKey(randKeyLen len);

private:
	string m_serverID;
	string m_dbUser;
	string m_dbPwd;
	string m_connStr;
	unsigned short m_port;
	map<pthread_t,TcpSocket*> m_map;
	TcpServer* m_tcpserver = NULL;
	OCCIFuc m_occi;
	SecretKeyShm* m_sks;
	
};
//void* work(void* arg);