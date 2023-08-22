#include "Hash.h"

Hash::Hash(HashType type)
{
	m_type = type;
	switch (m_type)
	{
	case T_MD5:
		initMD5();
		break;
	case T_SHA1:
		initSHA1();
		break;
	case T_SHA224:
		initSHA224();
		break;
	case T_SHA256:
		initSHA256();
		break;
	case T_SHA512:
		initSHA512();
		break;
		
	default:
		initMD5();
		break;
	}
}

void Hash::addData(string data)
{
	switch (m_type)
	{
	case T_MD5:
		adddateMD5(data.data());
		break;
	case T_SHA1:
		adddateSHA1(data.data());
		break;
	case T_SHA224:
		adddateSHA224(data.data());
		break;
	case T_SHA256:
		adddateSHA256(data.data());
		break;
	case T_SHA512:
		adddateSHA512(data.data());
		break;
	default:
		adddateMD5(data.data());
		break;
	}
}

string Hash::result()
{
	string re = string();
	switch (m_type)
	{
	case T_MD5:
		re=resultMD5();
		break;
	case T_SHA1:
		re = resultSHA1();
		break;
	case T_SHA224:
		re = resultSHA224();
		break;
	case T_SHA256:
		re = resultSHA256();
		break;
	case T_SHA512:
		re = resultSHA512();
		break;
	default:
		re = resultMD5();
		break;
	}
	return re;
}

string Hash::resultMD5()
{
	unsigned char md[MD5_DIGEST_LENGTH];
	 char res[MD5_DIGEST_LENGTH * 2 + 1];
	MD5_Final(md,&ctx);
	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return string(res, MD5_DIGEST_LENGTH * 2 + 1);

}

string Hash::resultSHA1()
{
	unsigned char md[SHA_DIGEST_LENGTH];
	char res[SHA_DIGEST_LENGTH * 2 + 1];
	SHA1_Final(md, &sha1);
	for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return string(res, SHA_DIGEST_LENGTH * 2 + 1);
}

string Hash::resultSHA224()
{
	unsigned char md[SHA224_DIGEST_LENGTH];
	char res[SHA224_DIGEST_LENGTH * 2 + 1];
	SHA224_Final(md, &sha224);
	for (int i = 0; i < SHA224_DIGEST_LENGTH; i++)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return string(res, SHA224_DIGEST_LENGTH * 2 + 1);
}

string Hash::resultSHA256()
{
	unsigned char md[SHA256_DIGEST_LENGTH];
	char res[SHA256_DIGEST_LENGTH * 2 + 1];
	SHA256_Final(md, &sha256);
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return string(res, SHA256_DIGEST_LENGTH * 2 + 1);
}

string Hash::resultSHA512()
{
	unsigned char md[SHA512_DIGEST_LENGTH];
	char res[SHA512_DIGEST_LENGTH * 2 + 1];
	SHA512_Final(md, &sha512);
	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return string(res, SHA512_DIGEST_LENGTH * 2 + 1);
}

Hash::~Hash()
{
}
