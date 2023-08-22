#pragma once
#include "ShmBase.h"
#include<iostream>
#include<string.h>
#include"SKSInfoNode.h"
using namespace std;


class SecretKeyShm :
    public ShmBase 
{
public:
    SecretKeyShm(int key, int nodeNum);
    SecretKeyShm(string filename, int nodeNum);
    ~SecretKeyShm();

    void SKS_Init();
    int SKS_Write(SKSInfoNode* info);
    SKSInfoNode SKS_Read(string clientID, string serverID);

private:
    int m_nodeNum;
   
};

