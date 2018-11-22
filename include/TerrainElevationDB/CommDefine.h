#ifndef TERRAINELEVATION_COMMDEFINE_H
#define TERRAINELEVATION_COMMDEFINE_H

#include <string>
/************************************************************************/
/* 数据库相关宏                                                                     */
/************************************************************************/

/* 数据库连接所需参数 */
#define DB_HOST_NAME "localhost"
#define DB_USER_NAME "root"
#define DB_PASSWORD "123456"
#define DB_PORT 0
#define DB_NAME "terrain_elevation_db"
#define DB_SOCKET_NAME nullptr
#define DB_FLAG 0

/* 数据块的大小 */
#define DB_BLOB_SIZE 10000

/************************************************************************/
/* 道路模型构造相关宏                                                                     */
/************************************************************************/

/* 构造跑道所需参数的常量 */
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

/* 数据象限标识 */
enum RoadQuadrantEnum
{
	RunwayQuadrantCount = -1,
	RunwayQuadrantFirst = 1,	/* 第一象限 */
	RunwayQuadrantSecond,		/* 第二象限 */
	RunwayQuadrantThird,		/* 第三象限 */
	RunwayQuadrantFouth			/* 第四象限 */
};

#endif // !TERRAINELEVATION_COMMDEFINE_H
