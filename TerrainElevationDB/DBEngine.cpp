#include <TerrainElevationDB/DBEngine.h>
#include <TerrainElevationDB/CommDefine.h>

#include <stdio.h>

using namespace TerrainElevation;

DBEngine* DBEngine::instance = nullptr;

DBEngine::DBEngine()
	:mySql(nullptr)
{
}

DBEngine::~DBEngine()
{
	closeDB();
}

DBEngine * DBEngine::getInstance()
{
	if (instance == nullptr)
	{
		instance = new DBEngine();
	}
	return instance;
}

bool DBEngine::connectDB()
{
	if (!mySql)
	{
		if (mysql_library_init(0, nullptr, nullptr))
		{
			printf("数据库服务初始化失败！");
			return false;
		}

		mySql = mysql_init(nullptr);

		if (mysql_options(mySql, MYSQL_SET_CHARSET_NAME, "utf8"))
		{
			printf("数据库字符集设置失败！");
			return false;
		}

		if (mysql_real_connect(mySql, db_host_name, db_user_name,
			db_password, db_name, db_port,
			db_socket_name, db_flag) == NULL)
		{
			printf("连接到数据库失败！");
			return false;
		}

	}
	
	return true;
}

void DBEngine::closeDB()
{
	if (mySql)
	{
		mysql_close(mySql);
		mysql_library_end();
	}
}
