#ifndef OPENCRG_H
#define OPENCRG_H

#include <MatlabEnginePub/Export.h>
#include <MatlabEnginePub/CommDefine.h>

#include <MatlabEnginePub/ConnectMatlab.h>
#include <MatlabEnginePub/CMatlab.h>

namespace MatlabEngine
{
	class MAMLATENGINEPUB_API OpenCRG
	{
	public:
		OpenCRG();
		virtual ~OpenCRG();

		bool setWorkPath(std::string path);

		bool initOpenCRGLibEnv();

		void setOpenCRGData(CurveData *data);

		void setComment(const std::string commnet);

		void setParmaterToMatlab();
		void update();

	protected:
		/** ±£´æÊý¾Ý */
		void save(std::string path, CRGDATATYPE type = KRBI);

		void setIncArray();
		void setUArray();
		void setVArray();
		void setCurveArray();
		void setSlopeArray();
		void setBankkingArray();

		void setZData();
	private:
		CMatlab *_matlab;
		ConnectMatlab *_connectMatlab;

		CurveData *_data;

		mxArray *_comment;
		mxArray *_zData;
		mxArray *_inc;
		mxArray *_u;
		mxArray *_v;
		mxArray *_curve;
		mxArray *_slope;
		mxArray *_bankking;

		mxArray *_CRGDataStruct;
	};
}


#endif // !OPENCRG_H
