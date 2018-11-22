#include <TerrainElevationDB/DBWriteRoadDataToSql.h>


TerrainElevation::DBWriteRoadDataToSql::DBWriteRoadDataToSql()
{
	mySqlEngine = DBMysqlEngine::getInstance();
}

TerrainElevation::DBWriteRoadDataToSql::~DBWriteRoadDataToSql()
{
	mySqlEngine->closeDB();
}

void TerrainElevation::DBWriteRoadDataToSql::writeData(float x, float y, float *zdata)
{
	char sql[DB_BLOB_SIZE * 5 + 1024], *end;
	sprintf(sql, "INSERT INTO terrain_elevation_table(x, y, zdata) VALUES (%f, %f,", x, y);
	end = sql + strlen(sql);
	*end++ = '\'';
	end += mysql_real_escape_string(mySqlEngine->getDB(), end, (char *)zdata, DB_BLOB_SIZE * sizeof(float));
	*end++ = '\'';
	*end++ = ')';

	int strLen = (int)(end - sql);

	if (mysql_real_query(mySqlEngine->getDB(), sql, strLen))
	{
		printf("Insert data default");
		return;
	}
	end = nullptr;
}