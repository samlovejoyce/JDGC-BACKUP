#ifndef DBREADROADDATAFROMSQL_H
#define DBREADROADDATAFROMSQL_H


#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/Database.h>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_API DatabaseRead
	{
	public:
		DatabaseRead();
		~DatabaseRead();

		float *readData(float xmin,/* float xmax,*/ float ymin/*, float ymax*/);
	
	private:
		Database *db;
	};
}

#endif // !DBREADROADDATAFROMSQL_H
