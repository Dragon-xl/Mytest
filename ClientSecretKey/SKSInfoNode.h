#pragma once
#include<string.h>
struct SKSInfoNode //Why Node:�ڽṹ������Node ʵ�ʵ�ÿһ��nodeΪһ����Կ ���߱��Ϊ 
    //��Կ�Ľڵ�
{
    SKSInfoNode() :status(0), seckID(0)
    {
        bzero(clientID, sizeof(clientID));
        bzero(serverID, sizeof(serverID));
        bzero(seckey, sizeof(seckey));
    }
    int status;// ��Կ״̬: 1����, 0:������
    int seckID; //��Կ���
    char clientID[12];
    char serverID[12];
    char seckey[128]; //�ԳƼ��ܵ���Կ
};
