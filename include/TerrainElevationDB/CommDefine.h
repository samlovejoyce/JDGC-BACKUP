#ifndef TERRAINELEVATION_COMMDEFINE_H
#define TERRAINELEVATION_COMMDEFINE_H

#include <string>
/************************************************************************/
/* ���ݿ���غ�                                                                     */
/************************************************************************/

/* ���ݿ������������ */
#define DB_HOST_NAME "localhost"
#define DB_USER_NAME "root"
#define DB_PASSWORD "123456"
#define DB_PORT 0
#define DB_NAME "terrain_elevation_db"
#define DB_SOCKET_NAME nullptr
#define DB_FLAG 0

/* ���ݿ�Ĵ�С */
#define DB_BLOB_SIZE 10000

/************************************************************************/
/* ��·ģ�͹�����غ�                                                                     */
/************************************************************************/

/* �����ܵ���������ĳ��� */
#define ROAD_RECT_LENGTH 487.5
#define ROAD_RECT_SMALL_WIDTH 107
#define ROAD_RECT_LARGE_WIDTH 125

#define ROAD_CIRCLE_INNER_RADIUS 107
#define ROAD_CIRCLE_OUT_RADIUS 125


struct RoadPointStruct
{
	float x;
	float y;
	float z;

	RoadPointStruct():x(0.0),y(0.0),z(0.0){}

	RoadPointStruct(float _x, float _y, float _z = 0.0) {
		x = _x;
		y = _y;
		z = _z;
	}
};

struct RoadRectangleStruct
{
	RoadPointStruct bottom;
	RoadPointStruct right;
	RoadPointStruct left;
	RoadPointStruct top;
};

struct RoadCircleStruct
{
	RoadPointStruct center;
	float outRadius;
	float innerRadius;

};

/* �������ޱ�ʶ */
enum RoadQuadrantEnum
{
	RunwayQuadrantCount = -1,
	RunwayQuadrantFirst = 1,	/* ��һ���� */
	RunwayQuadrantSecond,		/* �ڶ����� */
	RunwayQuadrantThird,		/* �������� */
	RunwayQuadrantFouth			/* �������� */
};

#endif // !TERRAINELEVATION_COMMDEFINE_H
