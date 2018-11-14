#ifndef DBENGINE_H
#define DBENGINE_H

#include <TerrainElevationDB/Export.h>

#include <mysql.h>

namespace TerrainElevation {

	class TERRAINELEVATIONDB_PAI DBEngine
	{
	public:
		~DBEngine();

		static DBEngine* getInstance();

		bool connectDB();

		MYSQL_RES *queryDB(MYSQL *mysql, const char *query);

		void closeDB();

		MYSQL* getDB() { return db; }

	private:
		static DBEngine* instance;
		DBEngine();

		MYSQL *db;

	};
}
#endif // !DBENGINE_H
