#include "Request.h"
using namespace std;

Request::Request()
{
}

Request::Request(std::string encstr)
{
	initMessage(encstr);
}

Request::Request(RequestInfo* info)
{
	initMessage(info);


}

void Request::initMessage(string encstr)
{
	m_encStr = encstr;
}

void Request::initMessage(RequestInfo* info)
{
	m_msg.set_cmd(info->cmd);
	m_msg.set_clientid(info->clientID);
	m_msg.set_serverid(info->serverID);
	m_msg.set_data(info->data);
	m_msg.set_sign(info->sign);

}

string Request::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);
	return output;
}

void* Request::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}

Request::~Request()
{
}
