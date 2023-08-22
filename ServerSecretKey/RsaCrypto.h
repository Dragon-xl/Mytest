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
	//生成RSA密钥对
	void generateRsakey(int bits, string pubfile="publickey.pem", string prifile="privatekey.pem");
	//公钥加密
	string encryptoPubKey(string data);
	//私钥解密
	string decryptoPriKey(string data);
	//RSA签名
	string signRsa(string data, whichHash hash = H_MD5);
	//RSA校验
	bool verifyRsa(string data, string signbuf,whichHash hash = H_MD5);
private:
	string toBase64(const char* str,int len);
	char* fromBase64(string str);
	//读出公钥
	bool initPubKey(string pubfile);
	//读出私钥
	bool initPriKey(string prifile);
private:
	RSA* m_pubkey ;
	RSA* m_prikey ;

};

