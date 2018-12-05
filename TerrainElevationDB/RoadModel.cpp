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
 * ����һ���㣬�ж��õ��Ƿ��ٸ����ľ���������
 * �ж�ԭ���ǣ�������ڸþ��������ڣ���õ�����ε��ĸ��㹹�ɵ��ĸ������ε�������ھ��ε����
 * ���򣬸õ㲻�ھ��������ڡ�
 */
bool TerrainElevation::RoadModel::isInRectArea(float x, float y, RoadRectStruct rect)
{
	bool ret = false;
	/** �ж�����ֵ�Ƿ�����Ч��ֵ */
	if (abs(y) < ROAD_RECT_SMALL_WIDTH)
		return ret;
	
	Pointf pt(x, y);

	/** ��ȡ���ε���� */
	float A = getRectArea(rect);

	/** pt���빹�ɾ��ε��ĸ��㹹�ɵ���� */
	float A1 = trangleArea(pt, rect.bottom, rect.left);
	float A2 = trangleArea(pt, rect.left, rect.top);
	float A3 = trangleArea(pt, rect.top, rect.right);
	float A4 = trangleArea(pt, rect.right, rect.bottom);

	ret = (A == A1 + A2 + A3 + A4);
	return ret;
}

/**
 * ����һ���㣬�ж��õ��Ƿ��ڻ���������
 * �ж�ԭ���㵽Բ�ĵľ���С��Բ����Բ�뾶�Ҵ���Բ����Բ�뾶��
 * ���򣬸õ㲻��Բ��������
 */
bool TerrainElevation::RoadModel::isInCircleArea(float x, float y, RoadCircleStruct circle)
{
	/** �ж�����ֵ�Ƿ�����Ч��ֵ */
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
	/* �ܵ����ĸ����ε����� */
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

	/* �ܵ��ĸ���Բ������ */
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
