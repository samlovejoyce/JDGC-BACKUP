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
	class TERRAINELEVATIONDB_PAI RoadModel
	{
	public:
		RoadModel();
		~RoadModel();

		/** ���Ƿ��ڹ���ĵ�·��״������ */
		bool isInRoadRectArea(float x, float y);
		bool isInRoadCircleArea(float x, float y);

		/** ���Ƿ��ھ��������� */
		bool isInRectArea(float x, float y, RoadRectStruct rect);

		/** ���Ƿ���Բ�������� */
		bool isInCircleArea(float x, float y, RoadCircleStruct circle);
		
		/** �ж������������ĸ����� */
		RoadQuadrantEnum getPointQuadrant(float x, float y);

	private:
		/** ��ʼ���ܵ����� */
		void initRoadShapeData();

		/** ������ε���� */
		float getRectArea(RoadRectStruct rect);

		/** ���������ε���� */
		float trangleArea(Pointf p1, Pointf p2, Pointf p3);

		/** �ж������ĵ��Ƿ������ķ�֮һԲ */
		bool checkInQuadrant(float x, float y, RoadCircleStruct circle);

	private:

		RoadRectStruct roadRectFirstQuadrant;		/** ���ε�һ���� */
		RoadRectStruct roadRectSecondQuadrant;		/** ���εڶ����� */
		RoadRectStruct roadRectThirdQuadrant;		/** ���ε������� */
		RoadRectStruct roadRectFourthQuadrant;		/** ���ε������� */

		RoadCircleStruct roadCircleFirstQuadrant;		/** Բ�ε�һ���� */
		RoadCircleStruct roadCircleSecondQuadrant;		/** Բ�εڶ����� */
		RoadCircleStruct roadCircleThirdQuadrant;		/** Բ�ε������� */
		RoadCircleStruct roadCircleFourthQuadrant;		/** Բ�ε������� */

	};
}

#endif // !TERRAINELEVATION_DBRUNWAY_H
