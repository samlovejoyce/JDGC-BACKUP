#ifndef DBREADROADDATAFROMSQL_H
#define DBREADROADDATAFROMSQL_H


#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/DBMysqlEngine.h>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_PAI DBReadRoadDataFromSql
	{
	public:
		DBReadRoadDataFromSql();
		~DBReadRoadDataFromSql();

		float *readData(float xmin, float xmax, float ymin, float ymax);
	
	private:
		DBMysqlEngine *mySqlEngine;
	};
}

#endif // !DBREADROADDATAFROMSQL_H
