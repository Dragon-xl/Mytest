#pragma once
#include "CodecFactory.h"
#include"Request.h"

class RequsetFactory :
    public CodecFactory
{
public:
    RequsetFactory(std::string enstr);
    RequsetFactory(RequestInfo* info);
    Codec* createCodecFactory();
    ~RequsetFactory();


private:
    int m_flag;
    std::string m_enstr;
    RequestInfo* m_info;

};

