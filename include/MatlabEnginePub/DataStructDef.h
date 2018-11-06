#ifndef DATASTRUCTDEF_H
#define DATASTRUCTDEF_H

#define STRING_CONNECT_MAC(parent, ...) (parent##"."##__VA_ARGS__)

//#define CRG_DATA "crgData"					/* 类型：struct */
//#define CRG_DATA_CT "ct"					/* 类型：cell */
//
//#define CRG_DATA_HEAD "head"				/* 类型：struct */
//#define CRG_DATA_HEAD_UBEG "ubeg"
//#define CRG_DATA_HEAD_UEND "uend"
//#define CRG_DATA_HEAD_UINC "uinc"
//#define CRG_DATA_HEAD_VMIN "vmin"
//#define CRG_DATA_HEAD_VMAX "vmax"
//#define CRG_DATA_HEAD_VINC "vinc"
//#define CRG_DATA_HEAD_SBEG "sbeg"
//#define CRG_DATA_HEAD_SEND "send"
//#define CRG_DATA_HEAD_BBEG "bbeg"
//#define CRG_DATA_HEAD_BEND "bend"
//#define CRG_DATA_HEAD_XBEG "xbeg"
//#define CRG_DATA_HEAD_YBEG "ybeg"
//#define CRG_DATA_HEAD_XEND "xend"
//#define CRG_DATA_HEAD_YEND "yend"
//#define CRG_DATA_HEAD_XOFF "xoff"
//#define CRG_DATA_HEAD_YOFF "yoff"
//#define CRG_DATA_HEAD_PBEG "pbeg"
//#define CRG_DATA_HEAD_PEND "pend"
//#define CRG_DATA_HEAD_POFF "poff"
//#define CRG_DATA_HEAD_ZBEG "zbeg"
//#define CRG_DATA_HEAD_ZEND "zend"
//#define CRG_DATA_HEAD_ZOFF "zoff"
//
//#define CRG_DATA_OPTS "opts"				/* 类型：struct */
//#define CRG_DATA_OPTS_BDMU "bdmu"
//#define CRG_DATA_OPTS_BDMV "bdmv"
//#define CRG_DATA_OPTS_BDOU "bdou"
//#define CRG_DATA_OPTS_BDOV "bdov"
//#define CRG_DATA_OPTS_BDSS "bdss"
//#define CRG_DATA_OPTS_BDSE "bdse"
//#define CRG_DATA_OPTS_RFLC "rflc"
//#define CRG_DATA_OPTS_SFAR "sfar"
//#define CRG_DATA_OPTS_SCLS "scls"
//#define CRG_DATA_OPTS_WMSG "wmsg"
//#define CRG_DATA_OPTS_WCVG "wcvg"
//#define CRG_DATA_OPTS_LMSG "lmsg"
//#define CRG_DATA_OPTS_LEVA "leva"
//#define CRG_DATA_OPTS_LHST "lhst"
//#define CRG_DATA_OPTS_LHSF "lhsf"
//#define CRG_DATA_OPTS_LSTF "lstf"
//#define CRG_DATA_OPTS_CEPS "ceps"
//#define CRG_DATA_OPTS_CTOL "ctol"
//#define CRG_DATA_OPTS_CINC "cinc"
//#define CRG_DATA_OPTS_WCLV "wclv"
//
//#define CRG_DATA_MODS  "mods"				/* 类型：struct */
//#define CRG_DATA_MODS_GNAN "gnan"
//#define CRG_DATA_MODS_RPFU "rpfu"
//#define CRG_DATA_MODS_RPOU "rpou"
//#define CRG_DATA_MODS_RPTV "rptv"
//#define CRG_DATA_MODS_RPOV "rpov"
//#define CRG_DATA_MODS_RPTX "rptx"
//#define CRG_DATA_MODS_RPTY "rpty"
//#define CRG_DATA_MODS_RPTZ "rptz"
//#define CRG_DATA_MODS_RPTP "rptp"
//
//#define CRG_DATA_STRUCT "struct"			/* 类型：cell */
//#define CRG_DATA_FILENM "filenm"			/* 类型：char */
//#define CRG_DATA_Z "z"
//#define CRG_DATA_V "v"
//#define CRG_DATA_U "u"
//#define CRG_DATA_P "p"
//#define CRG_DATA_DEVD "devd"				/* 类型：struct */
//#define CRG_DATA_IR "ir"
//#define CRG_DATA_IL "il"					/* 类型：(N x M) double*/
//#define CRG_DATA_HIST "hist"				/* 类型：struct */
//#define CRG_DATA_OK "ok"					/* 类型：double */


///* crgData数据结构所包含的域名 */
//const char *crgDataFiledName[] =
//{
//	CRG_DATA_HEAD,
//	CRG_DATA_OPTS,
//	CRG_DATA_CT,
//	CRG_DATA_MODS,
//	CRG_DATA_STRUCT,
//	CRG_DATA_FILENM,
//	CRG_DATA_Z,
//	CRG_DATA_V,
//	CRG_DATA_U,
//	CRG_DATA_P,
//	CRG_DATA_DEVD,
//	CRG_DATA_IR,
//	CRG_DATA_IL,
//	CRG_DATA_HIST,
//	CRG_DATA_OK
//};
//
//const int crgDataFiledLength = 15;
//
///* head数据结构所包含的域名 */
//const char *headFiledName[] =
//{
//	CRG_DATA_HEAD_UBEG,
//	CRG_DATA_HEAD_UEND,
//	CRG_DATA_HEAD_UINC,
//	CRG_DATA_HEAD_VMIN,
//	CRG_DATA_HEAD_VMAX,
//	CRG_DATA_HEAD_VINC,
//	CRG_DATA_HEAD_SBEG,
//	CRG_DATA_HEAD_SEND,
//	CRG_DATA_HEAD_BBEG,
//	CRG_DATA_HEAD_BEND,
//	CRG_DATA_HEAD_XBEG,
//	CRG_DATA_HEAD_YBEG,
//	CRG_DATA_HEAD_XEND,
//	CRG_DATA_HEAD_YEND,
//	CRG_DATA_HEAD_XOFF,
//	CRG_DATA_HEAD_YOFF,
//	CRG_DATA_HEAD_PBEG,
//	CRG_DATA_HEAD_PEND,
//	CRG_DATA_HEAD_POFF,
//	CRG_DATA_HEAD_ZBEG,
//	CRG_DATA_HEAD_ZEND,
//	CRG_DATA_HEAD_ZOFF
//};
//
//const int headFiledLength = 22;

/* crgData数据结构所包含的域名 */
#define CRG_DATA "data"					/* 类型：struct */
#define CRG_DATA_CT "ct"				/* 类型：cell */
#define CRG_DATA_Z "z"
#define CRG_DATA_V "v"
#define CRG_DATA_U "u"
#define CRG_DATA_B "b"
#define CRG_DATA_P "p"
#define CRG_DATA_S "s"
#define CRG_DATA_UINC "uinc"
#define CRG_DATA_VINC "vinc"

const char* crgDataFiledName[] =
{
	CRG_DATA_Z,
	CRG_DATA_V,
	CRG_DATA_U,
	CRG_DATA_CT,
	CRG_DATA_B,
	CRG_DATA_P,
	CRG_DATA_S
};

const int crgDataFiledLength = 7;

/*  crg数据结构 */
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

/* crg数据固定常量nv的值 */
const int crgDataNV = 201;

#endif
