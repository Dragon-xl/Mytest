#pragma once
#include "Codec.h"
#include<iostream>
#include"Message.pb.h"
using namespace std;


struct RequestInfo
{
    int cmd;
    string clientID;
    string serverID;
    string sign;
    string data;
};
class Request :
    public Codec
{
public:
    Request();
    Request(std::string encstr);
    Request(RequestInfo* info);
    void initMessage(std::string encstr);
    void initMessage(RequestInfo* info);
    std::string encodeMsg();
    void* decodeMsg();
    ~Request();
private:
    string m_encStr;
    ResquestMsg m_msg;

};

