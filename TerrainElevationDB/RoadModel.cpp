#include <TerrainElevationDB/RoadModel.h>
#include <cmath>

TerrainElevation::RoadModel::RoadModel()
{
	initRoadShapeData();
}

TerrainElevation::RoadModel::~RoadModel()
{
}

bool TerrainElevation::RoadModel::isInRoadRectArea(float x, float y)
{
	if(isInRectArea(x, y, roadRectFirstQuadrant) || isInRectArea(x, y, roadRectSecondQuadrant) ||
		isInRectArea(x, y, roadRectThirdQuadrant) || isInRectArea(x, y, roadRectFourthQuadrant)
		 )
		return true;
	return false;
}

bool TerrainElevation::RoadModel::isInRoadCircleArea(float x, float y)
{
	if (isInCircleArea(x, y, roadCircleFirstQuadrant) || isInCircleArea(x, y, roadCircleSecondQuadrant) ||
		isInCircleArea(x, y, roadCircleThirdQuadrant) || isInCircleArea(x, y, roadCircleFourthQuadrant))
		return true;
	return false;
}

/**
 * 给定一个点，判定该点是否再给定的矩形区域内
 * 判定原理是：如果点在该矩形区域内，则该点与矩形的四个点构成的四个三角形的面积等于矩形的面积
 * 否则，该点不在矩形区域内。
 */
bool TerrainElevation::RoadModel::isInRectArea(float x, float y, RoadRectStruct rect)
{
	bool ret = false;
	/** 判定输入值是否是有效的值 */
	if (abs(y) < ROAD_RECT_SMALL_WIDTH)
		return ret;
	
	Pointf pt(x, y);

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
bool TerrainElevation::RoadModel::isInCircleArea(float x, float y, RoadCircleStruct circle)
{
	/** 判定输入值是否是有效的值 */
	if (abs(x) < ROAD_RECT_LENGTH )
		return false;

	/**  */
	float dx = abs(x - circle.center.x);
	float dy = abs(y - circle.center.y);
	
	/*if(dx > circle.outRadius || dx < circle.innerRadius)
		return false;
	
	if (dy > circle.outRadius || dy < circle.innerRadius)
		return false;*/

	float distance = dx * dx + dy * dy;
	
	if (distance < circle.innerRadius * circle.innerRadius)
		return false;
	
	if (distance > circle.outRadius * circle.outRadius)
		return false;

	return checkInQuadrant(x, y, circle);
}

void TerrainElevation::RoadModel::initRoadShapeData()
{
	/* 跑道的四个矩形的数据 */
	roadRectFirstQuadrant.bottom = Pointf(0.0, ROAD_RECT_SMALL_WIDTH);
	roadRectFirstQuadrant.left = Pointf(0.0, ROAD_RECT_LARGE_WIDTH);
	roadRectFirstQuadrant.right = Pointf(ROAD_RECT_LENGTH, ROAD_RECT_SMALL_WIDTH);
	roadRectFirstQuadrant.top = Pointf(ROAD_RECT_LENGTH, ROAD_RECT_LARGE_WIDTH);

	roadRectSecondQuadrant.bottom = Pointf(-ROAD_RECT_LENGTH, ROAD_RECT_SMALL_WIDTH);
	roadRectSecondQuadrant.left = Pointf(-ROAD_RECT_LENGTH, ROAD_RECT_LARGE_WIDTH);
	roadRectSecondQuadrant.right = Pointf(0.0, ROAD_RECT_SMALL_WIDTH);
	roadRectSecondQuadrant.top = Pointf(0.0, ROAD_RECT_LARGE_WIDTH);


	roadRectThirdQuadrant.bottom = Pointf(-ROAD_RECT_LENGTH, -ROAD_RECT_LARGE_WIDTH);
	roadRectThirdQuadrant.left = Pointf(-ROAD_RECT_LENGTH, -ROAD_RECT_SMALL_WIDTH);
	roadRectThirdQuadrant.right = Pointf(0.0, -ROAD_RECT_LARGE_WIDTH);
	roadRectThirdQuadrant.top = Pointf(0.0, -ROAD_RECT_SMALL_WIDTH);

	roadRectFourthQuadrant.bottom = Pointf(0.0, -ROAD_RECT_LARGE_WIDTH);
	roadRectFourthQuadrant.left = Pointf(0.0, -ROAD_RECT_SMALL_WIDTH);
	roadRectFourthQuadrant.right = Pointf(ROAD_RECT_LENGTH, -ROAD_RECT_LARGE_WIDTH);
	roadRectFourthQuadrant.top = Pointf(ROAD_RECT_LENGTH, -ROAD_RECT_SMALL_WIDTH);

	/* 跑道四个半圆的数据 */
	roadCircleFirstQuadrant.center = Pointf(ROAD_RECT_LENGTH, 0.0);
	roadCircleFirstQuadrant.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadCircleFirstQuadrant.outRadius = ROAD_CIRCLE_OUT_RADIUS;
	
	roadCircleSecondQuadrant.center = Pointf(-ROAD_RECT_LENGTH, 0.0);
	roadCircleSecondQuadrant.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadCircleSecondQuadrant.outRadius = ROAD_CIRCLE_OUT_RADIUS;
	
	roadCircleThirdQuadrant.center = Pointf(-ROAD_RECT_LENGTH, 0.0);
	roadCircleThirdQuadrant.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadCircleThirdQuadrant.outRadius = ROAD_CIRCLE_OUT_RADIUS;
	
	roadCircleFourthQuadrant.center = Pointf(ROAD_RECT_LENGTH, 0.0);
	roadCircleFourthQuadrant.innerRadius = ROAD_CIRCLE_INNER_RADIUS;
	roadCircleFourthQuadrant.outRadius = ROAD_CIRCLE_OUT_RADIUS;
}

float TerrainElevation::RoadModel::getRectArea(RoadRectStruct rect)
{
	float aera = trangleArea(rect.bottom, rect.left, rect.right) + trangleArea(rect.right, rect.top, rect.left);
	return aera;
}

float TerrainElevation::RoadModel::trangleArea(Pointf p1, Pointf p2, Pointf p3)
{
	float area = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
	return abs(area);
}

RoadQuadrantEnum TerrainElevation::RoadModel::getPointQuadrant(float x, float y)
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

bool TerrainElevation::RoadModel::checkInQuadrant(float x, float y, RoadCircleStruct circle)
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
