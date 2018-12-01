#include <TerrainElevationDB/RoadElevationDataGeneration.h>
#include <time.h>


TerrainElevation::RoadElevationDataGeneration::RoadElevationDataGeneration()
	:dbRoadShapeData(nullptr)
	,dbWriteRoadDataToSql(nullptr)
{
	dbRoadShapeData = new RoadModel();
	dbWriteRoadDataToSql = new DatabaseWrite();
}

TerrainElevation::RoadElevationDataGeneration::~RoadElevationDataGeneration()
{
	if (dbRoadShapeData && dbWriteRoadDataToSql)
	{
		delete dbRoadShapeData;
		delete dbWriteRoadDataToSql;
	}
}

void TerrainElevation::RoadElevationDataGeneration::generateRectBlobData(float x, float y)
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
		
		/** 直接生成10000个个数据 */
		/*for(int i = 0; i < DB_BLOB_SIZE; i++)
			data[i] = -0.05 + float(rand() % 1000) / 10000.0;*/
		tempMutex.lock();
		
		dbWriteRoadDataToSql->writeData(x, y, data);
		delete [] data;

		tempMutex.unlock();
	}
}

void TerrainElevation::RoadElevationDataGeneration::generateCircleBolbData(float x, float y)
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

		/** 直接生成10000个个数据 */
		/*for(int i = 0; i < DB_BLOB_SIZE; i++)
		data[i] = -0.05 + float(rand() % 1000) / 10000.0;*/

		tempMutex.lock();

		dbWriteRoadDataToSql->writeData(x, y, data);
		delete[] data;

		tempMutex.unlock();
	}
}

void TerrainElevation::RoadElevationDataGeneration::generateRoadData()
{
	/**
	 * x、y每次增量0.5
	 * x的取值范围0 - 84.795
	 * y的取值范围0 - 42.6
	 * 跑道数据分象限生成，首先是第一现象矩形部分，然后是第一象限环形部分
	 */


	 generateDataThread[0] = std::thread(&RoadElevationDataGeneration::generateRectangleQuadrantData, this, RunwayQuadrantFirst);
	 generateDataThread[1] = std::thread(&RoadElevationDataGeneration::generateRectangleQuadrantData, this, RunwayQuadrantSecond);
	 generateDataThread[2] = std::thread(&RoadElevationDataGeneration::generateRectangleQuadrantData, this, RunwayQuadrantThird);
	 generateDataThread[3] = std::thread(&RoadElevationDataGeneration::generateRectangleQuadrantData, this, RunwayQuadrantFouth);

	 generateDataThread[4] = std::thread(&RoadElevationDataGeneration::generateCircleQuadrantData, this, RunwayQuadrantFirst);
	 generateDataThread[5] = std::thread(&RoadElevationDataGeneration::generateCircleQuadrantData, this, RunwayQuadrantSecond);
	 generateDataThread[6] = std::thread(&RoadElevationDataGeneration::generateCircleQuadrantData, this, RunwayQuadrantThird);
	 generateDataThread[7] = std::thread(&RoadElevationDataGeneration::generateCircleQuadrantData, this, RunwayQuadrantFouth);
	
	for (int i = 0; i < 8; i++)
		generateDataThread[i].join();

}

void TerrainElevation::RoadElevationDataGeneration::generateRectangleQuadrantData(RoadQuadrantEnum roadQuadrant)
{
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
	
	/** 生成从（xmin，ymin）到（xmax，ymax）之间的区块数据 */
	for (float x = xmin; x <= xmax; x += resulotion)
	{
		for (float y = ymin; y <= ymax; y += resulotion)
		{
			generateRectBlobData(x, y);
		}
	}
}

void TerrainElevation::RoadElevationDataGeneration::generateCircleQuadrantData(RoadQuadrantEnum roadQuadrant)
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
		ymin = 0.0;
		ymax = ROAD_RECT_LARGE_WIDTH;
	}
	break;
	case RunwayQuadrantSecond:
	{
		xmin = -(ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH);
		xmax = -ROAD_RECT_LENGTH;
		ymin = 0.0;
		ymax = ROAD_RECT_LARGE_WIDTH;
	}
	break;
	case RunwayQuadrantThird:
	{
		xmin = -(ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH);
		xmax = -ROAD_RECT_LENGTH;
		ymin = -ROAD_RECT_LARGE_WIDTH;
		ymax = 0.0;
	}
	break;
	case RunwayQuadrantFouth:
	{
		xmin = ROAD_RECT_LENGTH;
		xmax = ROAD_RECT_LENGTH + ROAD_RECT_LARGE_WIDTH;
		ymin = -ROAD_RECT_LARGE_WIDTH;
		ymax = 0.0;
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
