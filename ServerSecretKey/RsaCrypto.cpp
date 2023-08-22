#include "RsaCrypto.h"
#include<openssl/err.h>
#include<string.h>


RsaCrypto::RsaCrypto()
{
	m_pubkey = RSA_new();
	m_prikey = RSA_new();
}

RsaCrypto::RsaCrypto(string fileName, bool isPrivate)
{
	m_pubkey = RSA_new();
	m_prikey = RSA_new();
	if (isPrivate)
	{
		initPriKey(fileName);
	}
	else
	{
		initPubKey(fileName);
	}
}

RsaCrypto::~RsaCrypto()
{
	RSA_free(m_pubkey);
	RSA_free(m_prikey);
}

void RsaCrypto::generateRsakey(int bits, string pubfile, string prifile)
{
	RSA* rsa = RSA_new();
	BIGNUM* bn = BN_new();
	BN_set_word(bn, 17);
	RSA_generate_key_ex(rsa, bits, bn, NULL);
	
	BIO* bio = BIO_new_file(pubfile.data(), "w");
	
	
	PEM_write_bio_RSAPublicKey(bio,rsa);
	BIO_flush(bio);
	BIO_free(bio);

	BIO *pribio = BIO_new_file(prifile.data(), "w");
	PEM_write_bio_RSAPrivateKey(pribio, rsa, NULL, NULL, 0, NULL, NULL);
	BIO_flush(pribio);
	BIO_free(pribio);

	m_prikey =  RSAPrivateKey_dup(rsa);
	m_pubkey = RSAPublicKey_dup(rsa);
	BN_free(bn);
	RSA_free(rsa);
	
	
	 
}

string RsaCrypto::encryptoPubKey(string data)
{
	string str = string();
	int keyLen = RSA_size(m_pubkey);
	char* encode = new char[keyLen+1];
	//ret 加密后长度
	int ret =RSA_public_encrypt(data.size(), (const unsigned char *)data.data(), (unsigned char*)encode,m_pubkey , RSA_PKCS1_PADDING);
	if (ret == -1)
	{
		cout << "加密失败" << endl;
		return string();
	}
	if (ret > 0) {
		str = toBase64(encode, ret);
		cout << "加密成功" << endl;
	}
	delete[] encode;
	return str;
	
}

string RsaCrypto::decryptoPriKey(string data)
{
	char* redata = fromBase64(data);
	int kenLen = RSA_size(m_prikey);
	char* decode = new char[kenLen+1];
	int ret =RSA_private_decrypt(kenLen, (const unsigned char*)redata,(unsigned char *)decode,m_prikey,RSA_PKCS1_PADDING);
	if (ret == -1)
	{
		cout << "解密失败" << endl;
		return string();
	}
	string str = string(decode, ret);
	delete[] decode;
	delete[] redata;
	return str;
}

string RsaCrypto::signRsa(string data, whichHash hash)
{
	
	unsigned int len ;
	char* sigret = new char[1024];
	memset(sigret, 0, 1024);
	int ret = RSA_sign(hash, (const unsigned char*)data.data(), data.size(),(unsigned char*)sigret, &len, m_prikey);
	if (ret == -1)
	{
		ERR_print_errors_fp(stdout);
	}
	string str = toBase64(sigret,len);
	delete[] sigret;
	return str;

}

bool RsaCrypto::initPubKey(string pubfile)
{
	BIO* bio = BIO_new_file(pubfile.data(),"r");
	if (PEM_read_bio_RSAPublicKey(bio, &m_pubkey, NULL, NULL) == NULL)
	{
		ERR_print_errors_fp(stdout);
		return false;
	}
	BIO_free(bio);
	return true;
}

bool RsaCrypto::initPriKey(string prifile)
{
	BIO* bio = BIO_new_file(prifile.data(), "r");
	if (PEM_read_bio_RSAPrivateKey(bio, &m_prikey, NULL, NULL) == NULL)
	{
		ERR_print_errors_fp(stdout);
		return false;
	}
	BIO_free(bio);
	return true;
}

bool RsaCrypto::verifyRsa(string data,string signbuf, whichHash hash)
{

	
	int keyLen = RSA_size(m_pubkey);
	char* sign = fromBase64(signbuf);
	int ret = RSA_verify(hash, (const unsigned char*)data.data(), data.size(), (const unsigned char*)sign, keyLen, m_pubkey);
	if (ret == -1)
	{
		ERR_print_errors_fp(stdout);
	}
	if (ret != 1)
	{
		return false;
	}
		return true;
}

string RsaCrypto::toBase64(const char* str,int len)
{
	BIO* b64 = BIO_new(BIO_f_base64());
	BIO* mem = BIO_new(BIO_s_mem());
	b64 = BIO_push(b64, mem);
	BIO_write(b64, str, len);
	BIO_flush(b64);
	BUF_MEM* ptr = NULL;
	BIO_get_mem_ptr(b64, &ptr);
	string ret =string(ptr->data, ptr->length - 1);
	BIO_free_all(b64);
	return ret;
}

char* RsaCrypto::fromBase64(string str)
{
	int length = str.size();
	BIO* b64 = BIO_new(BIO_f_base64());
	BIO* mem = BIO_new_mem_buf(str.data(), length);
	b64 = BIO_push(b64, mem);
	char* buffer = new char[length];
	memset(buffer, 0, length);
	BIO_read(b64, buffer, length);
	BIO_free_all(b64);

	return buffer;
}







