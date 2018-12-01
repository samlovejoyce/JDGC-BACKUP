#ifndef TERRAINELEVATION_COMMDEFINE_H
#define TERRAINELEVATION_COMMDEFINE_H

#include <vector>
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
	Pointf center;			/** Բ�����ĵ� */
	float outRadius;		/** ��Բ�뾶 */
	float innerRadius;		/** ��Բ�뾶 */

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

/** ��·��С���ݴ洢��Ԫ���ݽṹ */
struct RoadDataBlobStruct
{
	float xmin;					/** ���ݿ�x����Сֵ */
	float xmax;					/** ���ݿ�x�����ֵ */
	float ymin;					/** ���ݿ�y����Сֵ */
	float ymax;					/** ���ݿ�y�����ֵ */
	float *zdata;

	/** Ĭ�Ϲ��캯�� */
	RoadDataBlobStruct() :xmin(0.0), xmax(0.0), ymin(0.0), ymax(0.0)
	{
		zdata = nullptr;
		//memset(zdata, 0, sizeof(float) * DB_BLOB_SIZE);
	}

	/** ���캯�� */
	RoadDataBlobStruct(float x1, float y1, float x2, float y2)
	{
		xmin = x1; xmax = x2; ymin = y1; ymax = y2;
		zdata = nullptr;
		//memset(zdata, 0, sizeof(float) * DB_BLOB_SIZE);
	}

	/** �����Ƿ���Ч */
	bool isEmpty();
	
	/** �������ݽṹ������ */
	void setData(Pointf &point);
	
};

namespace Math
{
	/** һ�����Բ�ֵ */
	extern float interpolate(std::vector<float> &xData, std::vector<float> &yData, float xi);

}

#endif // !TERRAINELEVATION_COMMDEFINE_H
