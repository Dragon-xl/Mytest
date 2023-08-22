#include "ServerFuc.h"
#include<json/json.h>
#include<fstream>
#include"TcpServer.h"
#include<unistd.h>
#include"CodecFactory.h"
#include"RequsetFactory.h"
#include"Message.pb.h"
#include"RsaCrypto.h"
#include"ResposeFactory.h"
#include"Hash.h"
#include"SKSInfoNode.h"
#include"SecretKeyShm.h"
using namespace Json;
using namespace std;
ServerFuc::ServerFuc(string json)
{
	ifstream ifs("server.json");
	Value root;
	Reader r;
	r.parse(ifs, root);
	m_port = root["port"].asInt();
	m_serverID = root["serverID"].asString();
	//DB
	string dbuser = root["userDB"].asString();
	string dbpwd = root["pwdDB"].asString();
	string connstr = root["connStrDB"].asString();
	m_occi.connectDB(dbuser,dbpwd,connstr);
	//SKS
	string filename = root["shmkey"].asString();
	int num = root["shmkeynum"].asInt();
	m_sks = new SecretKeyShm(filename, num);
}

ServerFuc::~ServerFuc()
{
	if (m_tcpserver)
	{
		delete m_tcpserver;
	}
	if (m_sks)
	{
		delete m_sks;
	}
}

void ServerFuc::startServer()
{
	int ret = 0;
	m_tcpserver = new TcpServer();
	ret = m_tcpserver->setListen(m_port);
	if (ret != 0)
	{
		cout << "setListen failed" << endl;
	}
	while (1)
	{
		cout << "wait connecting" << endl;
		TcpSocket* tsock = m_tcpserver->acceptConnect();
		if (tsock == NULL)
		{
			continue;
		}
		cout << "connect successfully" << endl;

		pthread_t ptid;
		pthread_create(&ptid, NULL,work, this);
		m_map.insert(make_pair(ptid,tsock));
	}

}

void* ServerFuc::work(void* arg)
{
	sleep(1);
	string encmsg = string();
	ServerFuc* sf = (ServerFuc*)arg;
	TcpSocket* tsock = sf->m_map[pthread_self()];
	string rec = tsock->recvMessage();
	CodecFactory* codecf = new RequsetFactory(rec);
	Codec* codec = codecf->createCodecFactory();
	ResquestMsg* rmsg = (ResquestMsg*)codec->decodeMsg();

	switch (rmsg->cmd())
	{
	case 1:
		 encmsg = sf->KeyAgreement(rmsg);
		break;
	default:
		break;
	}
	tsock->sendMessage(encmsg);
	tsock->disConnect();

	delete codecf;
	delete codec;
	delete tsock;
	sf->m_map.erase(pthread_self());
	return NULL;


}

string  ServerFuc::KeyAgreement(ResquestMsg* reqmsg)
{
	ResponseInfo res;
	ofstream ofs("publickey.pem");
	ofs << reqmsg->data();
	ofs.close();
	cout << reqmsg->data() << endl;
	RsaCrypto rsa("publickey.pem",false);
	Hash h(T_MD5);
	h.addData(reqmsg->data());
	string hr = h.result();
	bool bo =rsa.verifyRsa(hr, reqmsg->sign());
	if (bo == false)
	{
		cout << "Ç©ÃûÊ§°Ü" << endl;
		res.status = false;
		
	}
	string key = randKey(Len16);
	string seckey = rsa.encryptoPubKey(key);
	
	res.clientID = reqmsg->clientid();
	res.data = seckey;
	res.serverID = m_serverID;
	res.status = true;

	SKSInfoNode node;
	strcpy(node.clientID, res.clientID.data());
	strcpy(node.serverID, res.serverID.data());
	strcpy(node.seckey, key.data());
	node.seckID = m_occi.getKetID();
	res.seckID = node.seckID;
	node.status = 1;
	bool b =m_occi.writeSecretKey(&node);
	if (b)
	{
		m_occi.updataKeyID(node.seckID+1);
		//shmwrite
		m_sks->SKS_Write(&node);

	}
	else
	{
		res.status = false;

	}

	CodecFactory* cf = new 	ResposeFactory(&res);
	Codec* codec = cf->createCodecFactory();
	return codec->encodeMsg();
}

string ServerFuc::randKey(randKeyLen len)
{
	srand(time(NULL));
	//Êý×Ö£¬´óÐ´×ÖÄ¸£¬Ð¡Ð´×ÖÄ¸£¬ÌØÊâ·ûºÅ
	string key = string();
	char* a = "!@#$%^&*()";
	
	for (int i = 0; i < len; i++)
	{
		int type = rand() % 4;
		switch (type)
		{
		case 0://Ëæ»úÊý×Ö
			key.append(1, '0'+rand() % 10);
			break;
		case 1:
			key.append(1, 'a' + rand() % 26);
			break;
		case 2:
			key.append(1, 'A' + rand() % 26);
			break;
		case 3:
			key.append(1, a[rand()%strlen(a)]);
			break;
		
		}
	}
	return key;
}

//void* work(void* arg)
//{
//
//}
