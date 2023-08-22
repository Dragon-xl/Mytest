#pragma once
#include "CodecFactory.h"
#include"Response.h"
using namespace std;
class ResposeFactory :
    public CodecFactory
{
public:
    ResposeFactory(string enstr);
    ResposeFactory(ResponseInfo* info);
    Codec* createCodecFactory();
    ~ResposeFactory();
private:
    int m_flag;
    string m_enstr;
    ResponseInfo* m_info;

};

