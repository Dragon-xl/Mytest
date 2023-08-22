#pragma once
#include<iostream>
#include<sys/shm.h>
#include<sys/ipc.h>
using namespace std;
class ShmBase
{
public:
	//显而易见,有size是创建shmid 没有则是读取
	ShmBase(int key);
	ShmBase(int key, int size);
	ShmBase(string filename);
	ShmBase(string filename, int size);
	~ShmBase();

	//进程关联shm 
	void *relatedShm();
	int unrelatedShm();
	int delShm();
private:
	//其实这个感觉不封装也行 >_<！
	int getShmID(key_t key, size_t size, int shmflg);
private:
	int m_shmid;
protected:
	void* m_shmaddr = NULL;

};

