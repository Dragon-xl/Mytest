#include "ResposeFactory.h"

ResposeFactory::ResposeFactory(string enstr)
{
	m_flag = 0;
	m_enstr = enstr;
}

ResposeFactory::ResposeFactory(ResponseInfo* info)
{
	m_flag = 1;
	m_info = info;
}

Codec* ResposeFactory::createCodecFactory()
{
	Codec* codec = NULL;
	if (m_flag == 0)
	{
		codec = new Response(m_enstr);
	}
	else
	{
		codec = new Response(m_info);
	}
	return codec;
}

ResposeFactory::~ResposeFactory()
{
}
