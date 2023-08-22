#pragma once
#include<openssl/aes.h>
#include<iostream>
using namespace std;
class AesCrypto
{
public:
	AesCrypto(string key);
	~AesCrypto();
	string aesCbcEncrypto(string text);
	string aesCbcDecrypto(string encstr);

private:
	string aesCrypto(string data, int crypto);
	void generateIvec(unsigned char* ivec);

private:
	string m_key;
	AES_KEY m_enkey;
	AES_KEY m_dekey;
};

