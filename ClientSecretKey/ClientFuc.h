#pragma once
#include"SecretKeyShm.h"
#include<iostream>
using namespace std;
struct ClientInfo
{
	string serverID;
	string clientID;
	string ip;
	unsigned short port;
};
class ClientFuc
{
public:
	ClientFuc(string clientJson);
	~ClientFuc();

	bool KeyAgreement();
private:
	ClientInfo m_info;
	SecretKeyShm* m_sks;
};

