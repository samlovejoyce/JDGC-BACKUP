#include <TerrainElevationDB/DBRoadShapeData.h>
#include <cmath>

TerrainElevation::DBRoadShapeData::DBRoadShapeData()
{
	initRoadShapeData();
}

TerrainElevation::DBRoadShapeData::~DBRoadShapeData()
{
}

bool TerrainElevation::DBRoadShapeData::isInRoadRectArea(float x, float y)
{
	if(isInRectArea(x, y, roadDataRectQuadrantFirst) || isInRectArea(x, y, roadDataRectQuadrantSecond) ||
		isInRectArea(x, y, roadDataRectQuadrantThird) || isInRectArea(x, y, roadDataRectQuadrantFourth)
		 )
		return true;
	return false;
}

bool TerrainElevation::DBRoadShapeData::isInRoadCircleArea(float x, float y)
{
	if (isInCircleArea(x, y, roadDataCircleQuadrantFirst) || isInCircleArea(x, y, roadDataCircleQuadrantSecond) ||
		isInCircleArea(x, y, roadDataCircleQuadrantThird) || isInCircleArea(x, y, roadDataCircleQuadrantFourth))
		return true;
	return false;
}

/**
 * 给定一个点，判定该点是否再给定的矩形区域内
 * 判定原理是：如果点在该矩形区域内，则该点与矩形的四个点构成的四个三角形的面积等于矩形的面积
 * 否则，该点不在矩形区域内。
 */
bool TerrainElevation::DBRoadShapeData::isInRectArea(float x, float y, RoadRectangleStruct rect)
{
	bool ret = false;
	/** 判定输入值是否是有效的值 */
	if (abs(x) < ROAD_RECT_LENGTH && abs(y) < ROAD_RECT_SMALL_WIDTH)
		return ret;
	
	RoadPointStruct pt(x, y);

	/** 获取矩形的面积 */
	float A = getRectArea(rect);

	/** pt点与构成矩形的四个点构成的面积 */
	float A1 = trangleArea(pt, rect.bottom, rect.left);
	float A2 = trangleArea(pt, rect.left, rect.top);
	float A3 = trangleArea(pt, rect.top, rect.right);
	float A4 = trangleArea(pt, rect.right, rect.bottom);

	ret = (A == A1 + A2 + A3 + A4);
	return ret;
}

/**
 * 给定一个点，判定该点是否在环形区域内
 * 判定原理：点到圆心的距离小于圆环外圆半径且大于圆环内圆半径，
 * 否则，该点不在圆环区域内
 */
bool TerrainElevation::DBRoadShapeData::isInCircleArea(float x, float y, RoadCircleStruct circle)
{
	/** 判定输入值是否是有效的值 */
	if (abs(x) < ROAD_RECT_LENGTH && abs(y) < ROAD_RECT_SMALL_WIDTH)
		return false;

	/**  */
	float dx = abs(x - circle.center.x);
	float dy = abs(y - circle.center.y);
	
	if(dx > circle.outRadius || dx < circle.innerRadius)
		return false;
	
	if (dy > circle.outRadius || dy < circle.innerRadius)
		return false;

	float distance = dx * dx + dy * dy;
	
	if (distance < circle.innerRadius * circle.innerRadius)
		return false;
	
	if (distance > circle.outRadius * circle.outRadius)
		return false;

	return checkInQuadrant(x, y, circle);
}

void TerrainElevation::DBRoadShapeData::initRoadShapeData()
{
	/* 跑道的四个矩形的数据 */
	roadDataRectQuadrantFirst.bottom = RoadPointStruct(0.0, ROAD_RECT_SMALL_WIDTH);
	roadDataRectQuadrantFirst.left = RoadPointStruct(0.0, ROAD_RECT_LARGE_WIDTH);
	roadDataRectQuadrantFirst.right = RoadPointStruct(ROAD_RECT_LENGTH, ROAD_RECT_SMALL_WIDTH);
	roadDataRectQuadrantFirst.top = RoadPointStruct(ROAD_RECT_LENGTH, ROAD_RECT_LARGE_WIDTH);

	roadDataRectQuadrantSecond.bottom = RoadPointStruct(-ROAD_RECT_LENGTH, ROAD_RECT_SMALL_WIDTH);
	roadDataRectQuadrantSecond.left = RoadPointStruct(-ROAD_RECT_LENGTH, ROAD_RECT_LARGE_WIDTH);
	roadDataRectQuadrantSecond.right = RoadPointStruct(0.0, ROAD_RECT_SMALL_WIDTH);
	roadDataRectQuadrantSecond.top = RoadPointStruct(0.0, ROAD_RECT_LARGE_WIDTH);


	roadDataRectQuadrantThird.bottom = RoadPointStruct(-ROAD_RECT_LENGTH, -ROAD_RECT_LARGE_WIDTH);
	roadDataRectQuadrantThird.left = RoadPointStruct(-ROAD_RECT_LENGTH, -ROAD_RECT_SMALL_WIDTH);
	roadDataRectQuadrantThird.right = RoadPointStruct(0.0, -ROAD_RECT_LARGE_WIDTH);
	roadDataRectQuadrantThird.top = RoadPointStruct(0.0, -ROAD_RECT_SMALL_WIDTH);

	roadDataRectQuadrantFourth.bottom = RoadPointStruct(0.0, -ROAD_RECT_LARGE_WIDTH);
	roadDataRectQuadrantFourth.left = RoadPointStruct(0.0, -ROAD_RECT_SMALL_WIDTH);
	roadDataRectQuadrantFourth.right = RoadPointStruct(ROAD_RECT_LENGTH, -ROAD_RECT_LARGE_WIDTH);
	roadDataRectQuadrantFourth.top = RoadPointStruct(ROAD_RECT_LENGTH, -ROAD_RECT_SMALL_WIDTH);

	/* 跑道四个半圆的数据 */
	roadDataCircleQuadrantFirst.center = RoadPointStruct(ROAD_RECT_LENGTH, 0.0);
	roadDataCircleQuadrantFirst.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadDataCircleQuadrantFirst.outRadius = ROAD_CIRCLE_OUT_RADIUS;
	
	roadDataCircleQuadrantSecond.center = RoadPointStruct(-ROAD_RECT_LENGTH, 0.0);
	roadDataCircleQuadrantSecond.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadDataCircleQuadrantSecond.outRadius = ROAD_CIRCLE_OUT_RADIUS;
	
	roadDataCircleQuadrantThird.center = RoadPointStruct(-ROAD_RECT_LENGTH, 0.0);
	roadDataCircleQuadrantThird.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadDataCircleQuadrantThird.outRadius = ROAD_CIRCLE_OUT_RADIUS;
	
	roadDataCircleQuadrantFourth.center = RoadPointStruct(ROAD_RECT_LENGTH, 0.0);
	roadDataCircleQuadrantFourth.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadDataCircleQuadrantFourth.outRadius = ROAD_CIRCLE_OUT_RADIUS;
}

float TerrainElevation::DBRoadShapeData::getRectArea(RoadRectangleStruct rect)
{
	float aera = trangleArea(rect.bottom, rect.left, rect.right) + trangleArea(rect.right, rect.top, rect.left);
	return aera;
}

float TerrainElevation::DBRoadShapeData::trangleArea(RoadPointStruct p1, RoadPointStruct p2, RoadPointStruct p3)
{
	float area = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
	return abs(area);
}

RoadQuadrantEnum TerrainElevation::DBRoadShapeData::getPointQuadrant(float x, float y)
{

	RoadQuadrantEnum quadrant = RunwayQuadrantCount;
	if (x >= 0 )
	{
		if (y >= 0)
			quadrant = RunwayQuadrantFirst;
		else
			quadrant = RunwayQuadrantFouth;
	}
	else
	{
		if (y >= 0)
			quadrant = RunwayQuadrantSecond;
		else
			quadrant = RunwayQuadrantThird;
	}
	return quadrant;
}

bool TerrainElevation::DBRoadShapeData::checkInQuadrant(float x, float y, RoadCircleStruct circle)
{
	RoadQuadrantEnum quadrant = RunwayQuadrantCount;
	quadrant = getPointQuadrant(x, y);
	switch (quadrant)
	{
	case RunwayQuadrantCount:
		break;
	case RunwayQuadrantFirst:
		if (x > circle.center.x && y > circle.center.y)
			return true;
		else
			return false;
	case RunwayQuadrantSecond:
		if (x < circle.center.x && y > circle.center.y)
			return true;
		else
			return false;
	case RunwayQuadrantThird:
		if (x < circle.center.x && y < circle.center.y)
			return true;
		else
			return false;
	case RunwayQuadrantFouth:
		if (x > circle.center.x && y < circle.center.y)
			return true;
		else
			return false;
	default:
		break;
	}
	return false;
}
