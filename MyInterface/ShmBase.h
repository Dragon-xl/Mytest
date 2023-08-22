#pragma once
#include<iostream>
#include<sys/shm.h>
#include<sys/ipc.h>
using namespace std;
class ShmBase
{
public:
	//�Զ��׼�,��size�Ǵ���shmid û�����Ƕ�ȡ
	ShmBase(int key);
	ShmBase(int key, int size);
	ShmBase(string filename);
	ShmBase(string filename, int size);
	~ShmBase();

	//���̹���shm 
	void *relatedShm();
	int unrelatedShm();
	int delShm();
private:
	//��ʵ����о�����װҲ�� >_<��
	int getShmID(key_t key, size_t size, int shmflg);
private:
	int m_shmid;
protected:
	void* m_shmaddr = NULL;

};

