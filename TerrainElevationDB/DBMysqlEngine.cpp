#include <TerrainElevationDB/DBMysqlEngine.h>
#include <TerrainElevationDB/CommDefine.h>

#include <stdio.h>

using namespace TerrainElevation;

DBMysqlEngine* DBMysqlEngine::instance = nullptr;

DBMysqlEngine::DBMysqlEngine()
	:db(nullptr)
{
	connectDB();
}

DBMysqlEngine::~DBMysqlEngine()
{
	closeDB();
}

DBMysqlEngine * DBMysqlEngine::getInstance()
{
	if (instance == nullptr)
	{
		instance = new DBMysqlEngine();
	}
	return instance;
}

bool DBMysqlEngine::connectDB()
{
	if (!db)
	{
		if (mysql_library_init(0, nullptr, nullptr)) /* ��ʼ��MySQL�� */
		{
			printf("���ݿ�����ʼ��ʧ�ܣ�");
			return false;
		}

		db = mysql_init(nullptr); /* ��ʼ�����Ӵ������ */

		if (mysql_options(db, MYSQL_SET_CHARSET_NAME, "utf8"))
		{
			printf("���ݿ��ַ�������ʧ�ܣ�");
			return false;
		}

		/* ���ӵ������� */
		if ( mysql_real_connect(db, DB_HOST_NAME, DB_USER_NAME,
			DB_PASSWORD, DB_NAME, DB_PORT,
			DB_SOCKET_NAME, DB_FLAG) == NULL)
		{
			printf("���ӵ����ݿ�ʧ�ܣ�");
			return false;
		}

	}
	
	return true;
}

MYSQL_RES * TerrainElevation::DBMysqlEngine::queryDB(MYSQL * pdb, const char * query)
{
	MYSQL_RES *res = nullptr;
	if (mysql_real_query(pdb, query, strlen(query)) != 0)
		return nullptr;

	if (mysql_field_count(pdb) > 0)
	{
		if (!(res = mysql_store_result(pdb)))
			return nullptr;
	}

	return res;
}

void DBMysqlEngine::closeDB()
{
	if (db)
	{
		mysql_close(db); /* �ر���MySQL������������ */
		mysql_library_end(); /* ����MySQL���ʹ�� */
	}
}
