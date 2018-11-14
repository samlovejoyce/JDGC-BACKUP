#ifndef TERRAINELEVATION_COMMDEFINE_H
#define TERRAINELEVATION_COMMDEFINE_H

#include <string>

/* 数据库连接所需参数 */
#define db_host_name "localhost"
#define db_user_name "root"
#define db_password "123456"
#define db_port 0
#define db_name "terrain_elevation_db"
#define db_socket_name nullptr
#define db_flag 0

/* 数据块的大小 */
#define DB_BLOB_SIZE 10000

/* 构造跑道所需参数的常量 */
#define RUNWAY_LINE_LENGTH 42.195
#define RUNWAY_LINE_WIDTH 6.1
#define RUNWAY_LINE_WIDTH1 36.5
#define RUNWAY_LINE_WIDTH2 (RUNWAY_LINE_WIDTH1 + RUNWAY_LINE_WIDTH)

#define RUNWAY_CIRCLE_INNERRADIUS 36.5
#define RUNWAY_CIRCLE_OUTRADIUS 42.6


struct RunwayPoint
{
	float x;
	float y;
	float z;

	RunwayPoint():x(0.0),y(0.0),z(0.0){}

	RunwayPoint(float _x, float _y, float _z = 0.0) {
		x = _x;
		y = _y;
		z = _z;
	}
};

struct RunwayRectangle
{
	RunwayPoint bottom;
	RunwayPoint right;
	RunwayPoint left;
	RunwayPoint top;
};

struct RunwayCircle
{
	RunwayPoint center;
	float outRadius;
	float innerRadius;

};

/* 数据象限标识 */
enum RunwayQuadrant
{
	RunwayQuadrantCount = -1,
	RunwayQuadrantFirst = 1,	/* 第一象限 */
	RunwayQuadrantSecond,		/* 第二象限 */
	RunwayQuadrantThird,		/* 第三象限 */
	RunwayQuadrantFouth			/* 第四象限 */
};

#endif // !TERRAINELEVATION_COMMDEFINE_H
