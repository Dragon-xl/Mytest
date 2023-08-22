#include "Interface.h"
#include<json/json.h>
#include<fstream>
#include<string>
#include"SecretKeyShm.h"
#include"SKSInfoNode.h"
#include"AesCrypto.h"
#include<iostream>
using namespace Json;
using namespace std;
Interface::Interface(string jsonfile)
{
	ifstream ifs(jsonfile);
	Value root;
	Reader r;
	r.parse(ifs, root);
	string shmkey = root["shmkey"].asString();
	string serverID = root["serverID"].asString();
	string clientID = root["clientID"].asString();
	int num = root["shmkeynum"].asInt();

	SecretKeyShm sks(shmkey, num);
	SKSInfoNode node = sks.SKS_Read(clientID, serverID);
	m_key = node.seckey;
}

Interface::~Interface()
{
}

string Interface::encrypto(string str)
{
	AesCrypto aes(m_key);
	return aes.aesCbcEncrypto(str);
}

string Interface::decrypto(string str)
{
	AesCrypto aes(m_key);
	return aes.aesCbcDecrypto(str);
}
