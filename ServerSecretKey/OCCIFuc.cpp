#include "OCCIFuc.h"
#include"time.h"

OCCIFuc::OCCIFuc()
{
}

OCCIFuc::~OCCIFuc()
{
}

bool OCCIFuc::connectDB(string user, string pwd, string connstr)
{
	m_env = Environment::createEnvironment("utf-8", "utf-8");
	m_conn = m_env->createConnection(user, pwd, connstr);
	if (m_conn == NULL)
	{
		cout << "connectDB failed" << endl;
		return false;
	}
	cout << "connectDB success" << endl;
	return true;
}

int OCCIFuc::getKetID()
{
	int keyID = 0;
	string sql = "select ikeysn from SECMNG.KEYSN for update";
	Statement* stat = m_conn->createStatement(sql);
	ResultSet* set =  stat->executeQuery();
	if (set->next())
	{
		keyID = set->getInt(1);
	}

	stat->closeResultSet(set);
	m_conn->terminateStatement(stat);
	return keyID;
}

bool OCCIFuc::updataKeyID(int keyID)
{
	string sql = "update SECMNG.KEYSN set ikeysn = " + to_string(keyID);
	Statement* stat =  m_conn->createStatement(sql);
	stat->setAutoCommit(true);
	int ret = stat->executeUpdate();
	if (ret <= 0)
	{
		return false;
	}
	return true;

}

bool OCCIFuc::writeSecretKey(SKSInfoNode* node)
{
	char* sql = new char[1024];
	sprintf(sql, "Insert Into SECMNG.SECKEYINFO(clientid, serverid, keyid, createtime, state, seckey) \
		values('%s', '%s', %d, to_date('%s', 'yyyy-mm-dd hh24:mi:ss'), %d, '%s')"
		, node->clientID, node->serverID, node->seckID, getCurrentTime().data(), 1, node->seckey);
	cout << "sql:" << sql << endl;
	Statement* stat = m_conn->createStatement();
	stat->setSQL(sql);
	stat->setAutoCommit(true);
	bool b = stat->executeUpdate(sql);
	delete sql;
	m_conn->terminateStatement(stat);	
	return b;
}

void OCCIFuc::closeDB()
{
	m_env->terminateConnection(m_conn);
	Environment::terminateEnvironment(m_env);
}

string OCCIFuc::getCurrentTime()
{
	time_t ttime;
	time(&ttime);
	char currenttime[64];
	strftime(currenttime, sizeof(currenttime), "%Y-%m-%d %H:%M:%S", localtime(&ttime));
	return currenttime;
}
