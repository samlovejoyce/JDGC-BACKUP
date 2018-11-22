#ifndef DBENGINE_H
#define DBENGINE_H

#include <TerrainElevationDB/Export.h>

#include <mysql.h>

namespace TerrainElevation {

	class TERRAINELEVATIONDB_PAI DBMysqlEngine
	{
	public:
		~DBMysqlEngine();

		/** 返回数据库实例指针 */
		static DBMysqlEngine* getInstance();

		/** 连接到数据库服务是否成功 */
		bool connectDB();

		/** 数据库查询 */
		MYSQL_RES *queryDB(MYSQL *mysql, const char *query);

		/** 关闭数据库连接及服务 */
		void closeDB();

		/** 返回MYSQL实例指针 */
		MYSQL* getDB() { return db; }

	private:
		static DBMysqlEngine* instance;
		DBMysqlEngine();

		MYSQL *db;
	};
}
#endif // !DBENGINE_H
