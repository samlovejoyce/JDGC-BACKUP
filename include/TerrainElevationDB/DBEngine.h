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

		void closeDB();


		MYSQL* getDB() { return mySql; }

	private:
		static DBEngine* instance;
		DBEngine();

		MYSQL *mySql;

	};
}
#endif // !DBENGINE_H
