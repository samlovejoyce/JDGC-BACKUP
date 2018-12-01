#include <TerrainElevationDB/DatabaseWrite.h>


TerrainElevation::DatabaseWrite::DatabaseWrite()
{
	db = Database::getInstance();
}

TerrainElevation::DatabaseWrite::~DatabaseWrite()
{
	db->closeDB();
}

void TerrainElevation::DatabaseWrite::writeData(float x, float y, float *zdata)
{
	char sql[DB_BLOB_SIZE * 5 + 1024], *end;
	sprintf(sql, "INSERT INTO terrain_elevation_table(x, y, zdata) VALUES (%f, %f,", x, y);
	end = sql + strlen(sql);
	*end++ = '\'';
	end += mysql_real_escape_string(db->getDB(), end, (char *)zdata, DB_BLOB_SIZE * sizeof(float));
	*end++ = '\'';
	*end++ = ')';

	int strLen = (int)(end - sql);

	if (mysql_real_query(db->getDB(), sql, strLen))
	{
		printf("Insert data default");
		return;
	}
	end = nullptr;
}