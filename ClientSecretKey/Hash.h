#pragma once
#include<openssl/md5.h>
#include<openssl/sha.h>
#include<iostream>
#include<string.h>
using namespace std;
enum HashType
	{
		T_MD5,
		T_SHA1,
		T_SHA224,
		T_SHA256,
		T_SHA512
	};
class Hash
{
public:	
	Hash(HashType type);
	~Hash();

	void addData(string data);
	string result();
	
private:
	inline void initMD5() {  MD5_Init(&ctx); }
	inline void adddateMD5(const char* data) { MD5_Update(&ctx, data, strlen(data));}
	string resultMD5();

	inline void initSHA1() { SHA1_Init(&sha1); }
	inline void adddateSHA1(const char* data) { SHA1_Update(&sha1, data, strlen(data)); }
	string resultSHA1();

	inline void initSHA224() { SHA224_Init(&sha224); }
	inline void adddateSHA224(const char* data) { SHA224_Update(&sha224, data, strlen(data)); }
	string resultSHA224();

	inline void initSHA256() { SHA256_Init(&sha256); }
	inline void adddateSHA256(const char* data) { SHA256_Update(&sha256, data, strlen(data)); }
	string resultSHA256();

	inline void initSHA512() { SHA512_Init(&sha512); }
	inline void adddateSHA512(const char* data) { SHA512_Update(&sha512, data, strlen(data)); }
	string resultSHA512();
	
private:
	HashType m_type;
	MD5_CTX ctx ;
	SHA_CTX sha1;
	SHA256_CTX sha224;
	SHA256_CTX sha256;
	SHA512_CTX sha512;
		
};

