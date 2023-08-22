#include "ClientFuc.h"
#include<fstream>
#include<json/json.h>
#include"Request.h"
#include"RsaCrypto.h"
#include<sstream>
#include"Hash.h"
#include"CodecFactory.h"
#include"RequsetFactory.h"
#include"ResposeFactory.h"
#include"TcpSocket.h"
#include"SecretKeyShm.h"
#include"SKSInfoNode.h"
using namespace Json;
using namespace std;
ClientFuc::ClientFuc(string clientJson)
{
	ifstream ifs(clientJson);
	Reader r;
	Value root;
	r.parse(ifs, root);
	m_info.clientID = root["clientID"].asString();
	m_info.serverID = root["serverID"].asString();
	m_info.ip = root["ip"].asString();
	m_info.port = root["port"].asInt();
	
	string filename = root["shmkey"].asString();
	int num = root["shmkeynum"].asInt();

	m_sks = new SecretKeyShm(filename, num);
}

ClientFuc::~ClientFuc()
{
	delete m_sks;
}

bool ClientFuc::KeyAgreement()
{
	RsaCrypto rsa;
	
	rsa.generateRsakey(1024);
	
	ifstream ifs("publickey.pem");
	stringstream ss;
	ss << ifs.rdbuf();
	

	RequestInfo reqinfo;
	reqinfo.clientID = m_info.clientID;
	reqinfo.cmd = 1;
	reqinfo.serverID = m_info.serverID;
	reqinfo.data = ss.str();
	Hash h(T_MD5);
	h.addData(ss.str());
	reqinfo.sign = rsa.signRsa(h.result());
	CodecFactory* cf = new RequsetFactory(&reqinfo);
	Codec* codec =cf->createCodecFactory();
	string encode = codec->encodeMsg();
	
	delete cf;
	delete codec;
	
	//ͨ��
	TcpSocket *tcp = new TcpSocket;
	int ret =tcp->connectToHost(m_info.ip, m_info.port);
	cout << m_info.ip << m_info.port << endl;
	if (ret != 0)
	{
		cout << "����ʧ��" << endl;
		return false;
	}
	cout << "���ӳɹ�" << endl;
	
	int sendret = tcp->sendMessage(encode);
	cout << "sendret:" << sendret << endl;
	string msg = tcp->recvMessage();
	
	cf = new ResposeFactory(msg);
	codec = cf->createCodecFactory();
	ResponseMsg* res = (ResponseMsg*)codec->decodeMsg();
	if (!res->status())
	{
		cout << "��ԿЭ��ʧ��" << endl;
		return false;
	}
	string key =rsa.decryptoPriKey(res->data());
	cout << "�ԳƼ��ܵ���ԿΪ��" << key << endl;
	//sharedmem op
	SKSInfoNode info;
	strcpy(info.clientID, m_info.clientID.data());
	strcpy(info.serverID, m_info.serverID.data());
	strcpy(info.seckey, key.data());
	info.seckID = res->seckeyid();
	info.status = true;
	m_sks->SKS_Write(&info);
	
	delete cf;
	delete codec;
	tcp->disConnect();
	delete tcp;
	return true;
}
