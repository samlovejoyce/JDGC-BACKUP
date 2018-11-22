#ifndef TERRAINELEVATION_DBRUNWAY_H
#define TERRAINELEVATION_DBRUNWAY_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
//#include <TerrainElevationDB/DBEngine.h>

namespace TerrainElevation
{
	/**
	 * ���ɵ�·ģ�͵�������
	 */
	class TERRAINELEVATIONDB_PAI DBRoadShapeData
	{
	public:
		DBRoadShapeData();
		~DBRoadShapeData();

		/** ���Ƿ��ڹ���ĵ�·��״������ */
		bool isInRoadRectArea(float x, float y);
		bool isInRoadCircleArea(float x, float y);

		/** ���Ƿ��ھ��������� */
		bool isInRectArea(float x, float y, RoadRectangleStruct rect);

		/** ���Ƿ���Բ�������� */
		bool isInCircleArea(float x, float y, RoadCircleStruct circle);
		
		/** �ж������������ĸ����� */
		RoadQuadrantEnum getPointQuadrant(float x, float y);

	private:
		/** ��ʼ���ܵ����� */
		void initRoadShapeData();

		/** ������ε���� */
		float getRectArea(RoadRectangleStruct rect);

		/** ���������ε���� */
		float trangleArea(RoadPointStruct p1, RoadPointStruct p2, RoadPointStruct p3);

		/** �ж������ĵ��Ƿ������ķ�֮һԲ */
		bool checkInQuadrant(float x, float y, RoadCircleStruct circle);

	private:

		RoadRectangleStruct roadDataRectQuadrantFirst;		/** ���ε�һ���� */
		RoadRectangleStruct roadDataRectQuadrantSecond;		/** ���εڶ����� */
		RoadRectangleStruct roadDataRectQuadrantThird;		/** ���ε������� */
		RoadRectangleStruct roadDataRectQuadrantFourth;		/** ���ε������� */

		RoadCircleStruct roadDataCircleQuadrantFirst;		/** Բ�ε�һ���� */
		RoadCircleStruct roadDataCircleQuadrantSecond;		/** Բ�εڶ����� */
		RoadCircleStruct roadDataCircleQuadrantThird;		/** Բ�ε������� */
		RoadCircleStruct roadDataCircleQuadrantFourth;		/** Բ�ε������� */

	};
}

#endif // !TERRAINELEVATION_DBRUNWAY_H
