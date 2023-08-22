#pragma once
#include<iostream>
using namespace std;
class Interface
{
public:
	Interface(string jsonfile);
	~Interface();

	string encrypto(string str);
	string decrypto(string str);
private:
	string m_key;
};

