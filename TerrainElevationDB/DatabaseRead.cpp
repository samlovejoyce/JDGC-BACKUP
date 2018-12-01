#include <TerrainElevationDB/DatabaseRead.h>

TerrainElevation::DatabaseRead::DatabaseRead()
	:db(nullptr)
{
	db = Database::getInstance();
}

TerrainElevation::DatabaseRead::~DatabaseRead()
{
	if (db)
	{
		db->closeDB();
	}
}

float * TerrainElevation::DatabaseRead::readData(float xmin,/* float xmax,*/ float ymin/*, float ymax*/)
{
	MYSQL_RES *result = nullptr;
	MYSQL_ROW row;
	float *zdata = nullptr;
	char sql[1024];
	
	sprintf(sql, "SELECT x, y, zdata FROM terrain_elevation_table WHERE x = %f AND y = %f;", xmin, ymin);
	if (mysql_real_query(db->getDB(), sql, strlen(sql)) != 0)
	{
		zdata = nullptr;
	}

	if ((result = mysql_store_result(db->getDB())) != NULL)
	{
		if ((row = mysql_fetch_row(result)) != NULL)
		{
			zdata = new float[DB_BLOB_SIZE];
			memset(zdata, 0, sizeof(float) * DB_BLOB_SIZE);
			memcpy(zdata, row[2], DB_BLOB_SIZE * sizeof(float));
		}

	}

	mysql_free_result(result);
	return zdata;
}
