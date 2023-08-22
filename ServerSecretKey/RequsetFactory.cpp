#include "RequsetFactory.h"
using namespace std;
RequsetFactory::RequsetFactory(string enstr)
{
	m_flag = 0;
	m_enstr = enstr;
}

RequsetFactory::RequsetFactory(RequestInfo* info)
{
	m_flag = 1;
	m_info = info;                             
}

Codec* RequsetFactory::createCodecFactory()
{
	Codec* codec = NULL;
	if (m_flag == 0)
	{
		codec = new Request(m_enstr);
	}
	else
	{
		codec = new Request(m_info);
	}
	return codec;
}

RequsetFactory::~RequsetFactory()
{
}
