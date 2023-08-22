#include "SecretKeyShm.h"

SecretKeyShm::SecretKeyShm(int key, int nodeNum)
	:ShmBase(key,nodeNum*sizeof(struct SKSInfoNode)),m_nodeNum(nodeNum)
{
}

SecretKeyShm::SecretKeyShm(string filename, int nodeNum):
	ShmBase(filename,nodeNum*sizeof(struct SKSInfoNode)),m_nodeNum(nodeNum)
{
}

SecretKeyShm::~SecretKeyShm()
{
}

void SecretKeyShm::SKS_Init()
{
	if (m_shmaddr != NULL)
	{
		memset(m_shmaddr, 0, m_nodeNum * sizeof(struct SKSInfoNode));
	}
}

int SecretKeyShm::SKS_Write(SKSInfoNode* info)
{
	
		int ret = -1;
		SKSInfoNode* paddr = (SKSInfoNode*)relatedShm();
		if (paddr == NULL)
		{
			return ret;
		}
		SKSInfoNode* pnode=NULL;
		for (int i = 0; i < m_nodeNum; i++)
		{
			pnode = paddr + i;
			if (strcmp(pnode->clientID, info->clientID) == 0 && strcmp(pnode->serverID, info->serverID) == 0)
			{
				memcpy(pnode, info, sizeof(SKSInfoNode));
				unrelatedShm();
				cout << "写数据成功: 原数据被覆盖!" << endl;
				return 0;
			}
		}
		int i = 0;
		SKSInfoNode tmpnode;
		for ( i = 0; i < m_nodeNum; i++)
		{
			pnode = paddr + i;
			if (memcmp(&tmpnode, pnode, sizeof(SKSInfoNode) )== 0)
			{
				memcpy(pnode,info,sizeof(SKSInfoNode));
				cout << "写入数据成功，在新的节点写入" << endl;
				break;
			}
		}
		if (i == m_nodeNum)
		{
			ret = -1;
		}
		unrelatedShm();
		return ret;
	
}

SKSInfoNode SecretKeyShm::SKS_Read(string clientID, string serverID)
{
	SKSInfoNode* paddr = (SKSInfoNode*)relatedShm();
	if (paddr == NULL)
	{
		cout << "SKS_Read :: relatedShm failed" << endl;
		return SKSInfoNode();
	}
	SKSInfoNode* node;
	SKSInfoNode info;
	for (int i = 0; i < m_nodeNum; i++)
	{
		node = paddr + i;
		if (strcmp(node->clientID, clientID.data()) == 0 && strcmp(node->serverID, serverID.data()));
		{
			info = *node;
			cout << "clientID,serverID,seckID,seckey status" << endl;
			cout << info.clientID << info.serverID << info.seckID << info.seckey << info.status << endl;
			break;
		}
	}
	unrelatedShm();
	return info;
}
