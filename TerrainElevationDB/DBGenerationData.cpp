#include <TerrainElevationDB/DBGenerationData.h>
#include <time.h>


TerrainElevation::DBGenerationData::DBGenerationData()
	:dbRoadShapeData(nullptr)
	,dbWriteRoadDataToSql(nullptr)
{
	dbRoadShapeData = new DBRoadShapeData();
	dbWriteRoadDataToSql = new DBWriteRoadDataToSql();
}

TerrainElevation::DBGenerationData::~DBGenerationData()
{
	if (dbRoadShapeData && dbWriteRoadDataToSql)
	{
		delete dbRoadShapeData;
		delete dbWriteRoadDataToSql;
	}
}

void TerrainElevation::DBGenerationData::generateRectBlobData(float x, float y)
{
	float resulotion = 0.005;
	time_t tm = time(0);
	srand(tm);

	if (dbRoadShapeData->isInRoadRectArea(x, y))
	{
		float tempx;
		float tempy;
		int tempi;
		float *data = new float[DB_BLOB_SIZE];

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				tempx = x + (i * resulotion);
				tempy = y + (j * resulotion);
				tempi = (i * 100) + j;

				/*data[tempi] = 1.01;*/
				if (dbRoadShapeData->isInRoadRectArea(tempx, tempy))
				{
					data[tempi] = -0.05 + float(rand() % 1000) / 10000.0;
				}
				else
					data[tempi] = 1.01;
			}
		}
		
		/** ֱ������10000�������� */
		/*for(int i = 0; i < DB_BLOB_SIZE; i++)
			data[i] = -0.05 + float(rand() % 1000) / 10000.0;*/

		dbWriteRoadDataToSql->writeData(x, y, data);
		delete [] data;
	}
}

void TerrainElevation::DBGenerationData::generateCircleBolbData(float x, float y)
{
	float resulotion = 0.005;
	time_t tm = time(0);
	srand(tm);

	if (dbRoadShapeData->isInRoadCircleArea(x, y))
	{
		float tempx;
		float tempy;
		int tempi;
		float *data = new float[DB_BLOB_SIZE];

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				tempx = x + (i * resulotion);
				tempy = y + (j * resulotion);
				tempi = (i * 100) + j;

				/*data[tempi] = 1.01;*/
				if (dbRoadShapeData->isInRoadCircleArea(tempx, tempy))
				{
					data[tempi] = -0.05 + float(rand() % 1000) / 10000.0;
				}
				else
					data[tempi] = 1.01;
			}
		}

		/** ֱ������10000�������� */
		/*for(int i = 0; i < DB_BLOB_SIZE; i++)
		data[i] = -0.05 + float(rand() % 1000) / 10000.0;*/

		dbWriteRoadDataToSql->writeData(x, y, data);
		delete[] data;
	}
}

void TerrainElevation::DBGenerationData::generateRoadData()
{
	/**
	 * x��yÿ������0.5
	 * x��ȡֵ��Χ0 - 84.795
	 * y��ȡֵ��Χ0 - 42.6
	 * �ܵ����ݷ��������ɣ������ǵ�һ������β��֣�Ȼ���ǵ�һ���޻��β���
	 */

	generateDataThread[0] = std::thread(&DBGenerationData::generateRectangleQuadrantData, this, RunwayQuadrantFirst);
	generateDataThread[1] = std::thread(&DBGenerationData::generateRectangleQuadrantData, this, RunwayQuadrantSecond);
	generateDataThread[2] = std::thread(&DBGenerationData::generateRectangleQuadrantData, this, RunwayQuadrantThird);
	generateDataThread[3] = std::thread(&DBGenerationData::generateRectangleQuadrantData, this, RunwayQuadrantFouth);

	/*generateDataThread[4] = std::thread(&DBGenerationData::generateCircleQuadrantData, this, RunwayQuadrantFirst);
	generateDataThread[5] = std::thread(&DBGenerationData::generateCircleQuadrantData, this, RunwayQuadrantSecond);
	generateDataThread[6] = std::thread(&DBGenerationData::generateCircleQuadrantData, this, RunwayQuadrantThird);
	generateDataThread[7] = std::thread(&DBGenerationData::generateCircleQuadrantData, this, RunwayQuadrantFouth);*/
	
	for (int i = 0; i < 4; i++)
		generateDataThread[i].join();

	/*generateRectangleQuadrantData(RunwayQuadrantFirst);
	generateRectangleQuadrantData(RunwayQuadrantSecond);
	generateRectangleQuadrantData(RunwayQuadrantThird);
	generateRectangleQuadrantData(RunwayQuadrantFouth);*/
}

void TerrainElevation::DBGenerationData::generateRectangleQuadrantData(RoadQuadrantEnum roadQuadrant)
{
	std::mutex tempMutex;
	tempMutex.lock();

	float xmin = 0.0, xmax = 0.0, ymin = 0.0, ymax = 0.0;
	float resulotion = 0.5;

	switch (roadQuadrant)
	{
	case RunwayQuadrantCount:
	
		break;
	case RunwayQuadrantFirst:
	{
		xmin = 0;
		xmax = ROAD_RECT_LENGTH;
		ymin = ROAD_RECT_SMALL_WIDTH;
		ymax = ROAD_RECT_LARGE_WIDTH;
	}
		break;
	case RunwayQuadrantSecond:
	{
		xmin = -ROAD_RECT_LENGTH;
		xmax = 0;
		ymin = ROAD_RECT_SMALL_WIDTH;
		ymax = ROAD_RECT_LARGE_WIDTH;
	}
		break;
	case RunwayQuadrantThird:
	{
		xmin = -ROAD_RECT_LENGTH;
		xmax = 0;
		ymin = -ROAD_RECT_LARGE_WIDTH;
		ymax = -ROAD_RECT_SMALL_WIDTH;
	}
		break;
	case RunwayQuadrantFouth:
	{
		xmin = 0;
		xmax = ROAD_RECT_LENGTH;
		ymin = -ROAD_RECT_LARGE_WIDTH;
		ymax = -ROAD_RECT_SMALL_WIDTH;
	}
		break;
	default:
		break;
	}
	
	/** ���ɴӣ�xmin��ymin������xmax��ymax��֮����������� */
	for (float x = xmin; x <= xmax; x += resulotion)
	{
		for (float y = ymin; y <= ymax; y += resulotion)
		{
			generateRectBlobData(x, y);

		}
	}
	
	tempMutex.unlock();
}

void TerrainElevation::DBGenerationData::generateCircleQuadrantData(RoadQuadrantEnum roadQuadrant)
{
	std::mutex tempMutex;
	tempMutex.lock();

	float xmin = 0.0, xmax = 0.0, ymin = 0.0, ymax = 0.0;
	float resulotion = 0.5;

	switch (roadQuadrant)
	{
	case RunwayQuadrantCount:

		break;
	case RunwayQuadrantFirst:
	{
		xmin = ROAD_RECT_LENGTH;
		xmax = ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH;
		ymin = ROAD_RECT_SMALL_WIDTH;
		ymax = ROAD_RECT_LARGE_WIDTH;
	}
	break;
	case RunwayQuadrantSecond:
	{
		xmin = -(ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH);
		xmax = -ROAD_RECT_LENGTH;
		ymin = ROAD_RECT_SMALL_WIDTH;
		ymax = ROAD_RECT_LARGE_WIDTH;
	}
	break;
	case RunwayQuadrantThird:
	{
		xmin = -(ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH);
		xmax = -ROAD_RECT_LENGTH;
		ymin = -ROAD_RECT_LARGE_WIDTH;
		ymax = -ROAD_RECT_SMALL_WIDTH;
	}
	break;
	case RunwayQuadrantFouth:
	{
		xmin = ROAD_RECT_LENGTH;
		xmax = ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH;
		ymin = -ROAD_RECT_LARGE_WIDTH;
		ymax = -ROAD_RECT_SMALL_WIDTH;
	}
	break;
	default:
		break;
	}

	for (float x = xmin; x <= xmax; x += resulotion)
	{
		for (float y = ymin; y <= ymax; y += resulotion)
		{
			generateCircleBolbData(x, y);
		}
	}
	tempMutex.unlock();
}
