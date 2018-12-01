#ifndef TERRAINELEVATION_DBRUNWAY_H
#define TERRAINELEVATION_DBRUNWAY_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
//#include <TerrainElevationDB/DBEngine.h>

namespace TerrainElevation
{
	/**
	 * 构成道路模型的数据类
	 */
	class TERRAINELEVATIONDB_PAI RoadModel
	{
	public:
		RoadModel();
		~RoadModel();

		/** 点是否在构造的道路形状区域内 */
		bool isInRoadRectArea(float x, float y);
		bool isInRoadCircleArea(float x, float y);

		/** 点是否在矩形区域内 */
		bool isInRectArea(float x, float y, RoadRectStruct rect);

		/** 点是否在圆形区域内 */
		bool isInCircleArea(float x, float y, RoadCircleStruct circle);
		
		/** 判定给定点属于哪个象限 */
		RoadQuadrantEnum getPointQuadrant(float x, float y);

	private:
		/** 初始化跑道参数 */
		void initRoadShapeData();

		/** 计算矩形的面积 */
		float getRectArea(RoadRectStruct rect);

		/** 计算三角形的面积 */
		float trangleArea(Pointf p1, Pointf p2, Pointf p3);

		/** 判定给定的点是否属于四分之一圆 */
		bool checkInQuadrant(float x, float y, RoadCircleStruct circle);

	private:

		RoadRectStruct roadRectFirstQuadrant;		/** 矩形第一象限 */
		RoadRectStruct roadRectSecondQuadrant;		/** 矩形第二象限 */
		RoadRectStruct roadRectThirdQuadrant;		/** 矩形第三象限 */
		RoadRectStruct roadRectFourthQuadrant;		/** 矩形第四象限 */

		RoadCircleStruct roadCircleFirstQuadrant;		/** 圆形第一象限 */
		RoadCircleStruct roadCircleSecondQuadrant;		/** 圆形第二象限 */
		RoadCircleStruct roadCircleThirdQuadrant;		/** 圆形第三象限 */
		RoadCircleStruct roadCircleFourthQuadrant;		/** 圆形第四象限 */

	};
}

#endif // !TERRAINELEVATION_DBRUNWAY_H
