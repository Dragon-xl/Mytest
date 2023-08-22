#pragma once
#include "Codec.h"
#include"Message.pb.h"
using namespace std;
struct ResponseInfo
{
    bool status;
    int seckID;
    string clientID;
    string serverID;
    string data;


};
class Response :
    public Codec
{
public:
    Response();
    Response(std::string encstr);
    Response(ResponseInfo* info);
    void initMessage(std::string encstr);
    void initMessage(ResponseInfo* info);
    std::string encodeMsg();
    void* decodeMsg();
    ~Response();
private:
    string m_encStr;
    ResponseMsg m_msg;
    
};

