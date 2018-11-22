#include <TerrainElevationDB/DBReadRoadDataFromSql.h>

TerrainElevation::DBReadRoadDataFromSql::DBReadRoadDataFromSql()
	:mySqlEngine(nullptr)
{
	mySqlEngine = DBMysqlEngine::getInstance();
}

TerrainElevation::DBReadRoadDataFromSql::~DBReadRoadDataFromSql()
{
	if (mySqlEngine)
	{
		mySqlEngine->closeDB();
	}
}

float * TerrainElevation::DBReadRoadDataFromSql::readData(float x, float y)
{
	MYSQL_RES *result = nullptr;
	MYSQL_ROW row;
	float *zdata = nullptr;
	char sql[1024];
	int i = 0, j = 0;
	while (true)
	{
		if (((abs(x) - i * 0.5) > 0) && ((abs(x) - (i + 1) * 0.5) < 0))
			break;
		i++;
	}
	while (true)
	{
		if (((abs(y) - j * 0.5) > 0) && ((abs(y) - (j + 1) * 0.5) < 0))
			break;
		j++;
	}
	float xmin;
	float xmax;
	float ymin;
	float ymax;
	if (x >= 0.0)
	{
		xmin = i * 0.5;
		xmax = (i + 1) * 0.5;
	}
	else
	{
		xmin = -((i + 1) * 0.5);
		xmax = -(i * 0.5);
	}
	if (y >= 0.0)
	{
		ymin = j * 0.5;
		ymax = (j + 1) * 0.5;
	}
	else
	{
		ymin = -((j + 1) * 0.5);
		ymax = -(j * 0.5);
	}
	sprintf(sql, "SELECT x, y, zdata FROM terrain_elevation_table WHERE x >= %f AND x < %f AND y >= %f AND y < %f;", xmin, xmax, ymin, ymax);
	if (mysql_real_query(mySqlEngine->getDB(), sql, strlen(sql)) != 0)
	{
		zdata = nullptr;
	}

	if ((result = mysql_store_result(mySqlEngine->getDB())) != NULL)
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
