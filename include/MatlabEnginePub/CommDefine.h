/************************************************************************/
/*	ע�����������ݽṹ����                                                                     */
/************************************************************************/
#ifndef DATASTRUCTDEF_H
#define DATASTRUCTDEF_H

#include <vector>

#define STRING_CONNECT_MAC(parent, ...) (parent##"."##__VA_ARGS__)

/* crgData���ݽṹ������������ */
#define CRG_DATA "data"					/* ���ͣ�struct */
#define CRG_DATA_CT "ct"				/* ���ͣ�cell */
#define CRG_DATA_Z "z"
#define CRG_DATA_V "v"
#define CRG_DATA_U "u"
#define CRG_DATA_B "b"
#define CRG_DATA_C "c"
#define CRG_DATA_S "s"
#define CRG_DATA_UINC "uinc"
#define CRG_DATA_VINC "vinc"
#define CRG_DATA_INC "inc"
/** crg���ݽṹ�ĸ����ֶ����� */
const char* crgDataFiledName[] =
{
	CRG_DATA_Z,
	CRG_DATA_V,
	CRG_DATA_U,
	CRG_DATA_CT,
	CRG_DATA_B,
	CRG_DATA_C,
	CRG_DATA_S
};

/** crg���ݽṹ�ֶγ��� */
#define CRG_DATA_FILED_LENGTH 7


/************************************************************************/
/*                                                                      */
/************************************************************************/
/**  crg���ݽṹ */
struct CrgData
{
	double crgDataUEnd;
	double crgDataUInc;
	double crgDataVMax;
	double crgDataVInc;
	double crgDataPhiEnd;
	double crgDataPhiInc;
	double crgDataBankingEnd;
	double crgDataBankingInc;
	double crgDataSlopeEnd;
	double crgDataSlopeInc;

	CrgData():crgDataUEnd(0.0),crgDataUInc(0.0),crgDataVMax(0.0),crgDataVInc(0.0),
		crgDataPhiEnd(0.0),crgDataPhiInc(0.0),crgDataBankingEnd(0.0), crgDataBankingInc(0.0),
		crgDataSlopeEnd(0.0),crgDataSlopeInc(0.0){ }
	
	CrgData(double uend, double uinc, double vmax, double vinc, double pend, double pinc, double bend, double binc, double send, double sinc)
	{
		crgDataUEnd = uend;
		crgDataUInc = uinc;
		crgDataVMax = vmax;
		crgDataVInc = vinc;
		crgDataPhiEnd = pend;
		crgDataPhiInc = pinc;
		crgDataBankingEnd = bend;
		crgDataBankingInc = binc;
		crgDataSlopeEnd = send;
		crgDataSlopeInc = sinc; 
	}

	CrgData(CrgData *data)
	{
		crgDataUEnd = data->crgDataUEnd;
		crgDataUInc = data->crgDataUInc;
		crgDataVMax = data->crgDataVMax;
		crgDataVInc = data->crgDataVInc;
		crgDataPhiEnd = data->crgDataPhiEnd;
		crgDataPhiInc = data->crgDataPhiInc;
		crgDataBankingEnd = data->crgDataBankingEnd;
		crgDataBankingInc = data->crgDataBankingInc;
		crgDataSlopeEnd = data->crgDataSlopeEnd;
		crgDataSlopeInc = data->crgDataSlopeInc;
	}

	CrgData &operator = (CrgData &data)
	{
		this->crgDataUEnd = data.crgDataUEnd;
		this->crgDataUInc = data.crgDataUInc;
		this->crgDataVMax = data.crgDataVMax;
		this->crgDataVInc = data.crgDataVInc;
		this->crgDataPhiEnd = data.crgDataPhiEnd;
		this->crgDataPhiInc = data.crgDataPhiInc;
		this->crgDataBankingEnd = data.crgDataBankingEnd;
		this->crgDataBankingInc = data.crgDataBankingInc;
		this->crgDataSlopeEnd = data.crgDataSlopeEnd;
		this->crgDataSlopeInc = data.crgDataSlopeInc;

		return *this;
	}
	
	CrgData *operator = (CrgData *data)
	{
		this->crgDataUEnd = data->crgDataUEnd;
		this->crgDataUInc = data->crgDataUInc;
		this->crgDataVMax = data->crgDataVMax;
		this->crgDataVInc = data->crgDataVInc;
		this->crgDataPhiEnd = data->crgDataPhiEnd;
		this->crgDataPhiInc = data->crgDataPhiInc;
		this->crgDataBankingEnd = data->crgDataBankingEnd;
		this->crgDataBankingInc = data->crgDataBankingInc;
		this->crgDataSlopeEnd = data->crgDataSlopeEnd;
		this->crgDataSlopeInc = data->crgDataSlopeInc;

		return this;
	}

};

/** crg���ݹ̶�����nv��ֵ */
#define CRG_DATA_NV 201

/** openCRG��MATLAB�������ļ� */
#define CRG_MATLAB_LIB_PATH "..\\OpenCRG.1.1.2\\matlab"


/************************************************************************/
/*                                                                      */
/************************************************************************/

/**
 * ����CRG���ߵĻ����������
 */
struct RoadCurveBase
{
	float length;
	float radiusStart;
	float radiusEnd;

	RoadCurveBase():length(0.0),radiusStart(0.0),radiusEnd(0.0){}
	
	RoadCurveBase &operator=(const RoadCurveBase other) {
		length = other.length;
		radiusStart = other.radiusStart;
		radiusEnd = other.radiusEnd;
		return *this;
	}
};

/**
 * ��·��������
 */
typedef std::vector<RoadCurveBase> CURVE_VECTOR;

struct RoadCurveData
{
	float uben;				/** u��x���������ʼ�� */
	float uend;				/** u��x������Ľ����� */
	float uinc;				/** u��x����������� */
	float vben;				/** v��y���������ʼ�� */
	float vend;				/** v��y������Ľ����� */
	float vinc;				/** v��y����������� */
	CURVE_VECTOR curve;		/** ���������� */
	CURVE_VECTOR slope;		/** ��·�������ϣ��¶ȣ����� */
	CURVE_VECTOR banking;	/** ��·�������ϵ����� */

	float *zData;			/** ��·�߳����� */
};

/**
 * CRG���ݴ洢����
 */
enum CRGDATATYPE {
	KRBI = 0,		// 'KRBI'  binary float32
	KDBI,           // 'KDBI'  binary float64
	LRFI,			// 'LRFI'  ascii single precision
	LDFI			// 'LDFI'  ascii double precision
};

static float *rowMajorToColMajor(const int row, const int col, float **data)
{
	float *tempData = new float[row * col];

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			tempData[i * row + j] = data[j][i];
		}
	}
	return tempData;
}

static float *colMajorToRowMajor(const int row, const int col, float **data)
{

}

#endif
