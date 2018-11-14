#ifndef TERRAINELEVATION_DBRUNWAY_H
#define TERRAINELEVATION_DBRUNWAY_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
//#include <TerrainElevationDB/DBEngine.h>

namespace TerrainElevation
{
	class TERRAINELEVATIONDB_PAI DBRunway
	{
	public:
		DBRunway();
		~DBRunway();

		bool isInArea(float x, float y);
		bool isInRectArea(float x, float y, RunwayRectangle rect);
		bool isInCircleArea(float x, float y, RunwayCircle circle);

	private:
		/* ��ʼ���ܵ����� */
		void initRunwayData();

		/* ��ȡ���ε������С */
		float getRectArea(RunwayRectangle rect);
		float trangleArea(RunwayPoint p1, RunwayPoint p2, RunwayPoint p3);

		RunwayQuadrant getPointQuadrant(float x, float y);
		bool checkInQuadrant(float x, float y, RunwayCircle circle);

	private:

		RunwayRectangle runwayRectQuadrantFirst;
		RunwayRectangle runwayRectQuadrantSecond;
		RunwayRectangle runwayRectQuadrantThird;
		RunwayRectangle runwayRectQuadrantFourth;

		RunwayCircle runwayCircleQuadrantFirst;
		RunwayCircle runwayCircleQuadrantSecond;
		RunwayCircle runwayCircleQuadrantThird;
		RunwayCircle runwayCircleQuadrantFourth;

	};
}

#endif // !TERRAINELEVATION_DBRUNWAY_H
