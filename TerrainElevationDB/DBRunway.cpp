#include <TerrainElevationDB/DBRunway.h>
#include <cmath>

TerrainElevation::DBRunway::DBRunway()
{
	//dbengine = DBEngine::getInstance();
	initRunwayData();
}

TerrainElevation::DBRunway::~DBRunway()
{
}

bool TerrainElevation::DBRunway::isInArea(float x, float y)
{
	if(isInRectArea(x, y, runwayRectQuadrantFirst) || isInRectArea(x, y, runwayRectQuadrantSecond) ||
		isInRectArea(x, y, runwayRectQuadrantThird) || isInRectArea(x, y, runwayRectQuadrantFourth) ||
		isInCircleArea(x, y, runwayCircleQuadrantFirst) || isInCircleArea(x, y, runwayCircleQuadrantSecond) ||
		isInCircleArea(x, y, runwayCircleQuadrantThird) || isInCircleArea(x, y, runwayCircleQuadrantFourth) )
		return true;
	return false;
}

bool TerrainElevation::DBRunway::isInRectArea(float x, float y, RunwayRectangle rect)
{
	RunwayPoint pt(x, y);
	float A = getRectArea(rect);

	float A1 = trangleArea(pt, rect.bottom, rect.left);

	float A2 = trangleArea(pt, rect.left, rect.top);

	float A3 = trangleArea(pt, rect.top, rect.right);

	float A4 = trangleArea(pt, rect.right, rect.bottom);

	return ( A == A1 + A2 + A3 + A4);
}

bool TerrainElevation::DBRunway::isInCircleArea(float x, float y, RunwayCircle circle)
{
	float dx = abs(x - circle.center.x);
	float dy = abs(y - circle.center.y);
	if(dx > circle.outRadius || dx < circle.innerRadius)
		return false;
	if (dy > circle.outRadius || dx < circle.innerRadius)
		return false;

	float distance = dx * dx + dy * dy;
	
	if (distance < circle.innerRadius * circle.innerRadius)
		return false;
	if (distance > circle.outRadius * circle.outRadius)
		return false;

	return checkInQuadrant(x, y, circle);
}

void TerrainElevation::DBRunway::initRunwayData()
{
	/* 跑道的四个矩形的数据 */
	runwayRectQuadrantFirst.bottom = RunwayPoint(0.0, RUNWAY_LINE_WIDTH1);
	runwayRectQuadrantFirst.left = RunwayPoint(RUNWAY_LINE_LENGTH, RUNWAY_LINE_WIDTH1);
	runwayRectQuadrantFirst.right = RunwayPoint(0.0, RUNWAY_LINE_WIDTH2);
	runwayRectQuadrantFirst.top = RunwayPoint(RUNWAY_LINE_LENGTH, RUNWAY_LINE_WIDTH2);

	runwayRectQuadrantSecond.bottom = RunwayPoint(-RUNWAY_LINE_LENGTH, RUNWAY_LINE_WIDTH1);
	runwayRectQuadrantSecond.left = RunwayPoint(-RUNWAY_LINE_LENGTH, RUNWAY_LINE_WIDTH2);
	runwayRectQuadrantSecond.right = RunwayPoint(0.0, RUNWAY_LINE_WIDTH1);
	runwayRectQuadrantSecond.top = RunwayPoint(0.0, RUNWAY_LINE_WIDTH2);


	runwayRectQuadrantThird.bottom = RunwayPoint(-RUNWAY_LINE_LENGTH, -RUNWAY_LINE_WIDTH2);
	runwayRectQuadrantThird.left = RunwayPoint(-RUNWAY_LINE_LENGTH, -RUNWAY_LINE_WIDTH1);
	runwayRectQuadrantThird.right = RunwayPoint(0.0, -RUNWAY_LINE_WIDTH2);
	runwayRectQuadrantThird.top = RunwayPoint(0.0, -RUNWAY_LINE_WIDTH1);

	runwayRectQuadrantFourth.bottom = RunwayPoint(0.0, -RUNWAY_LINE_WIDTH2);
	runwayRectQuadrantFourth.left = RunwayPoint(0.0, -RUNWAY_LINE_WIDTH1);
	runwayRectQuadrantFourth.right = RunwayPoint(RUNWAY_LINE_LENGTH, -RUNWAY_LINE_WIDTH2);
	runwayRectQuadrantFourth.top = RunwayPoint(RUNWAY_LINE_LENGTH, -RUNWAY_LINE_WIDTH1);

	/* 跑道四个半圆的数据 */
	runwayCircleQuadrantFirst.center = RunwayPoint(RUNWAY_LINE_LENGTH, 0.0);
	runwayCircleQuadrantFirst.innerRadius = RUNWAY_CIRCLE_INNERRADIUS;
	runwayCircleQuadrantFirst.outRadius = RUNWAY_CIRCLE_OUTRADIUS;
	
	runwayCircleQuadrantSecond.center = RunwayPoint(-RUNWAY_LINE_LENGTH, 0.0);
	runwayCircleQuadrantSecond.innerRadius = RUNWAY_CIRCLE_INNERRADIUS;
	runwayCircleQuadrantSecond.outRadius = RUNWAY_CIRCLE_OUTRADIUS;
	
	runwayCircleQuadrantThird.center = RunwayPoint(-RUNWAY_LINE_LENGTH, 0.0);
	runwayCircleQuadrantThird.innerRadius = RUNWAY_CIRCLE_INNERRADIUS;
	runwayCircleQuadrantThird.outRadius = RUNWAY_CIRCLE_OUTRADIUS;
	
	runwayCircleQuadrantFourth.center = RunwayPoint(RUNWAY_LINE_LENGTH, 0.0);
	runwayCircleQuadrantFourth.innerRadius = RUNWAY_CIRCLE_INNERRADIUS;
	runwayCircleQuadrantFourth.outRadius = RUNWAY_CIRCLE_OUTRADIUS;
}

float TerrainElevation::DBRunway::getRectArea(RunwayRectangle rect)
{
	float aera = trangleArea(rect.bottom, rect.left, rect.right) + trangleArea(rect.right, rect.top, rect.left);
	return aera;
}

float TerrainElevation::DBRunway::trangleArea(RunwayPoint p1, RunwayPoint p2, RunwayPoint p3)
{
	float area = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0;
	return abs(area);
}

RunwayQuadrant TerrainElevation::DBRunway::getPointQuadrant(float x, float y)
{

	RunwayQuadrant quadrant = RunwayQuadrantCount;
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

bool TerrainElevation::DBRunway::checkInQuadrant(float x, float y, RunwayCircle circle)
{
	RunwayQuadrant quadrant = RunwayQuadrantCount;
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
