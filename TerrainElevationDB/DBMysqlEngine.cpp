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
		if (mysql_library_init(0, nullptr, nullptr)) /* 初始化MySQL库 */
		{
			printf("数据库服务初始化失败！");
			return false;
		}

		db = mysql_init(nullptr); /* 初始化连接处理程序 */

		if (mysql_options(db, MYSQL_SET_CHARSET_NAME, "utf8"))
		{
			printf("数据库字符集设置失败！");
			return false;
		}

		/* 连接到服务器 */
		if ( mysql_real_connect(db, DB_HOST_NAME, DB_USER_NAME,
			DB_PASSWORD, DB_NAME, DB_PORT,
			DB_SOCKET_NAME, DB_FLAG) == NULL)
		{
			printf("连接到数据库失败！");
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
		mysql_close(db); /* 关闭与MySQL服务器的连接 */
		mysql_library_end(); /* 结束MySQL库的使用 */
	}
}
