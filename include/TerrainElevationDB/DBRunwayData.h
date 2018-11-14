#ifndef DBRUNWAYDATA_H
#define DBRUNWAYDATA_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/DBEngine.h>
#include <TerrainElevationDB/DBRunway.h>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_PAI DBRunwayData
	{
	public:
		DBRunwayData();
		~DBRunwayData();

		void writeDataTDB(float x, float y, float *zdata);
		float *readZDataFromDB(float x, float y);

	private:
		DBEngine *mySqlEngine;
		DBRunway *dbRunway;

	};
}

#endif // !DBRUNWAYDATA_H
