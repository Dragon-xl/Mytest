#pragma once
#include<occi.h>
#include<iostream>
#include"SKSInfoNode.h"
using namespace std;
using namespace oracle::occi;
class OCCIFuc
{
public:
	OCCIFuc();
	~OCCIFuc();

	bool connectDB(string user, string pwd, string connstr);
	int getKetID();
	bool updataKeyID(int keyID);
	bool writeSecretKey(SKSInfoNode* node);
	void closeDB();
private:
	string getCurrentTime();
private:
	Environment* m_env = NULL;
	Connection* m_conn = NULL;



};


