#pragma once
#include<iostream>
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/bio.h>
#include<openssl/md5.h>
#include<openssl/sha.h>
using namespace std;


enum whichHash
{
	H_MD5= NID_md5,
	H_SHA1 = NID_sha1,
	H_SHA224= NID_sha224,
	H_SHA256 = NID_sha256,
	H_SHA512= NID_sha512
};
class RsaCrypto
{

public:
	RsaCrypto();
	RsaCrypto(string fileName, bool isPrivate = true);
	~RsaCrypto();
	//����RSA��Կ��
	void generateRsakey(int bits, string pubfile="publickey.pem", string prifile="privatekey.pem");
	//��Կ����
	string encryptoPubKey(string data);
	//˽Կ����
	string decryptoPriKey(string data);
	//RSAǩ��
	string signRsa(string data, whichHash hash = H_MD5);
	//RSAУ��
	bool verifyRsa(string data, string signbuf,whichHash hash = H_MD5);
private:
	string toBase64(const char* str,int len);
	char* fromBase64(string str);
	//������Կ
	bool initPubKey(string pubfile);
	//����˽Կ
	bool initPriKey(string prifile);
private:
	RSA* m_pubkey ;
	RSA* m_prikey ;

};

