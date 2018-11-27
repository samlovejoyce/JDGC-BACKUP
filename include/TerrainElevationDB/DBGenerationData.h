#ifndef DBGENERATIONDATA_H
#define DBGENERATIONDATA_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/DBRoadShapeData.h>
#include <TerrainElevationDB/DBWriteRoadDataToSql.h>

#include <mutex>
#include <thread>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_PAI DBGenerationData
	{
	public:
		DBGenerationData();
		~DBGenerationData();

		/**
		 * ���ɵ������ݿ������
		 */
		void generateRectBlobData(float x, float y);

		void generateCircleBolbData(float x, float y);

		/**
		 * ���������ܵ�������
		 */
		void generateRoadData();

		/** ���ɵ�·���������ڵ����� */
		void generateRectangleQuadrantData(RoadQuadrantEnum roadQuadrant);

		void generateCircleQuadrantData(RoadQuadrantEnum roadQuadrant);

	private:
		DBRoadShapeData *dbRoadShapeData;
		DBWriteRoadDataToSql *dbWriteRoadDataToSql;

		std::mutex tempMutex;
		std::thread generateDataThread[8];
	};
}
#endif // !DBGENERATIONDATA_H
