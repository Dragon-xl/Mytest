#include "Response.h"
using namespace std;

Response::Response()
{
}

Response::Response(string encstr)
{
	initMessage(encstr);
}

Response::Response(ResponseInfo* info)
{
	initMessage(info);
}

void Response::initMessage(string encstr)
{
	m_encStr = encstr;
}

void Response::initMessage(ResponseInfo* info)
{
	m_msg.set_status(info->status);
	m_msg.set_seckeyid(info->seckID);
	m_msg.set_clientid(info->clientID);
	m_msg.set_serverid(info->serverID);
	m_msg.set_data(info->data);
}

string Response::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void* Response::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}

Response::~Response()
{
}

