#include "AesCrypto.h"

AesCrypto::AesCrypto(string key)
{
	if (key.size() == 16 || key.size() == 24 || key.size() == 32)
	{
		m_key = key;
		unsigned char* userkey = (unsigned char*)key.data();
		AES_set_encrypt_key(userkey, key.size()*8, &m_enkey);//单位bit 因此要*8
		AES_set_decrypt_key(userkey, key.size()*8, &m_dekey);
	}
}

AesCrypto::~AesCrypto()
{

}

string AesCrypto::aesCbcEncrypto(string text)
{

	return aesCrypto(text, AES_ENCRYPT);
}

string AesCrypto::aesCbcDecrypto(string encstr)
{
	return aesCrypto(encstr, AES_DECRYPT);
}

string AesCrypto::aesCrypto(string data, int crypto)
{
	AES_KEY key = crypto == AES_ENCRYPT ? m_enkey : m_enkey;
	 char* in = (char*)data.c_str();
	int length = sizeof(in);
	if (length % 16)
	{
		length = (length / 16 + 1) * 16;
	}
	unsigned char* out = new unsigned char[length];
	unsigned char ivec[AES_BLOCK_SIZE];
	generateIvec(ivec);
	AES_cbc_encrypt((unsigned char*)in, out,length,&key,ivec,crypto);
	string str = string((char *)out);
	delete[]out;
	return str;
}

void AesCrypto::generateIvec(unsigned char* ivec)
{
	for (int i = 0; i < AES_BLOCK_SIZE; i++)
	{
		ivec[i] = m_key.at(AES_BLOCK_SIZE - i - 1);
	}
}
