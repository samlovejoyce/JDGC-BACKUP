#ifndef TERRAINELEVATION_COMMDEFINE_H
#define TERRAINELEVATION_COMMDEFINE_H

#include <vector>
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


struct Pointf
{
	float x;
	float y;
	float z;

	Pointf():x(0.0),y(0.0),z(0.0){}

	Pointf(float _x, float _y, float _z = 0.0) {
		x = _x;
		y = _y;
		z = _z;
	}

	Pointf operator =(Pointf p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		
		return *this;
	}
};

struct RoadRectStruct
{
	Pointf bottom;
	Pointf right;
	Pointf left;
	Pointf top;
};

struct RoadCircleStruct
{
	Pointf center;			/** 圆的中心点 */
	float outRadius;		/** 内圆半径 */
	float innerRadius;		/** 外圆半径 */

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

/** 道路最小数据存储单元数据结构 */
struct RoadDataBlobStruct
{
	float xmin;					/** 数据块x的最小值 */
	float xmax;					/** 数据块x的最大值 */
	float ymin;					/** 数据块y的最小值 */
	float ymax;					/** 数据块y的最大值 */
	float *zdata;

	/** 默认构造函数 */
	RoadDataBlobStruct() :xmin(0.0), xmax(0.0), ymin(0.0), ymax(0.0)
	{
		zdata = nullptr;
		//memset(zdata, 0, sizeof(float) * DB_BLOB_SIZE);
	}

	/** 构造函数 */
	RoadDataBlobStruct(float x1, float y1, float x2, float y2)
	{
		xmin = x1; xmax = x2; ymin = y1; ymax = y2;
		zdata = nullptr;
		//memset(zdata, 0, sizeof(float) * DB_BLOB_SIZE);
	}

	/** 数据是否有效 */
	bool isEmpty();
	
	/** 设置数据结构的数据 */
	void setData(Pointf &point);
	
};

namespace Math
{
	/** 一次线性插值 */
	extern float interpolate(std::vector<float> &xData, std::vector<float> &yData, float xi);

}

#endif // !TERRAINELEVATION_COMMDEFINE_H
