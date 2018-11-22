#ifndef DBRUNWAYDATA_H
#define DBRUNWAYDATA_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/DBMysqlEngine.h>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_PAI DBWriteRoadDataToSql
	{
	public:
		DBWriteRoadDataToSql();
		~DBWriteRoadDataToSql();

		void writeData(float x, float y, float *zdata);

	private:
		DBMysqlEngine *mySqlEngine;

	};
}

#endif // !DBRUNWAYDATA_H
