#ifndef DBRUNWAYDATA_H
#define DBRUNWAYDATA_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/Database.h>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_PAI DatabaseWrite
	{
	public:
		DatabaseWrite();
		~DatabaseWrite();

		void writeData(float x, float y, float *zdata);

	private:
		Database *db;

	};
}

#endif // !DBRUNWAYDATA_H
