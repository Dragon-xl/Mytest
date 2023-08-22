#include "ShmBase.h"
#include<sys/shm.h>
#include<sys/ipc.h>

using namespace std;
const char Pid = 'x';
int ShmBase::getShmID(key_t key, size_t size, int shmflg)
{
	 m_shmid= shmget(key, size, shmflg);
	if (m_shmid == -1)
	{
		cout << "shmget failed" << endl;
	}
	else
	{
		cout << "shmid:" << m_shmid << endl;
	}
	return m_shmid;
}

ShmBase::ShmBase(int key)
{
	getShmID(key, 0, 0);
}

ShmBase::ShmBase(int key, int size)
{
	getShmID(key, size, IPC_CREAT | 0664);

}

ShmBase::ShmBase(string filename)
{
	key_t key = ftok(filename.data(), Pid);
	getShmID(key, 0, 0);
}

ShmBase::ShmBase(string filename, int size)
{
	key_t key = ftok(filename.data(), Pid);
	getShmID(key, size, IPC_CREAT | 0664);

}

ShmBase::~ShmBase()
{
}

void* ShmBase::relatedShm()
{
	m_shmaddr = shmat(m_shmid, NULL, 0);
	if (m_shmaddr == (void*)-1)
	{
		cout << "ShmBase::relatedShm failed" << endl;
		return NULL;
	}
	return m_shmaddr;
}

int ShmBase::unrelatedShm()
{
	int ret = shmdt(m_shmaddr);
	if (ret == -1)
	{
		cout << "ShmBase::unrelatedShm failed" << endl;
		return -1;
	}
	return ret;//ret = 0
}

int ShmBase::delShm()
{
	int ret = shmctl(m_shmid, IPC_RMID, NULL);
	if (ret == -1)
	{
		cout << "ShmBase::delShm() failed" << endl;
		return -1;
	}
	return 0;
}
