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
	class TERRAINELEVATIONDB_PAI DBRoadShapeData
	{
	public:
		DBRoadShapeData();
		~DBRoadShapeData();

		/** 点是否在构造的道路形状区域内 */
		bool isInRoadRectArea(float x, float y);
		bool isInRoadCircleArea(float x, float y);

		/** 点是否在矩形区域内 */
		bool isInRectArea(float x, float y, RoadRectangleStruct rect);

		/** 点是否在圆形区域内 */
		bool isInCircleArea(float x, float y, RoadCircleStruct circle);
		
		/** 判定给定点属于哪个象限 */
		RoadQuadrantEnum getPointQuadrant(float x, float y);

	private:
		/** 初始化跑道参数 */
		void initRoadShapeData();

		/** 计算矩形的面积 */
		float getRectArea(RoadRectangleStruct rect);

		/** 计算三角形的面积 */
		float trangleArea(RoadPointStruct p1, RoadPointStruct p2, RoadPointStruct p3);

		/** 判定给定的点是否属于四分之一圆 */
		bool checkInQuadrant(float x, float y, RoadCircleStruct circle);

	private:

		RoadRectangleStruct roadDataRectQuadrantFirst;		/** 矩形第一象限 */
		RoadRectangleStruct roadDataRectQuadrantSecond;		/** 矩形第二象限 */
		RoadRectangleStruct roadDataRectQuadrantThird;		/** 矩形第三象限 */
		RoadRectangleStruct roadDataRectQuadrantFourth;		/** 矩形第四象限 */

		RoadCircleStruct roadDataCircleQuadrantFirst;		/** 圆形第一象限 */
		RoadCircleStruct roadDataCircleQuadrantSecond;		/** 圆形第二象限 */
		RoadCircleStruct roadDataCircleQuadrantThird;		/** 圆形第三象限 */
		RoadCircleStruct roadDataCircleQuadrantFourth;		/** 圆形第四象限 */

	};
}

#endif // !TERRAINELEVATION_DBRUNWAY_H
