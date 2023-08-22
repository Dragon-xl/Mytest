#pragma once
#include<string.h>
struct SKSInfoNode //Why Node:在结构中类似Node 实际的每一个node为一个密钥 或者表达为 
    //密钥的节点
{
    SKSInfoNode() :status(0), seckID(0)
    {
        bzero(clientID, sizeof(clientID));
        bzero(serverID, sizeof(serverID));
        bzero(seckey, sizeof(seckey));
    }
    int status;// 密钥状态: 1可用, 0:不可用
    int seckID; //密钥编号
    char clientID[12];
    char serverID[12];
    char seckey[128]; //对称加密的密钥
};
