#ifndef MATLAB_ENGINE_H
#define MATLAB_ENGINE_H

#include <MatlabEnginePub/Export.h>
#include <MatlabEnginePub/DataStructDef.h>

#include <engine.h>
#include <matrix.h>
#include <mclcppclass.h>
#include <string>
#include <vector>


namespace MATLABENGINE {

	class MAMLATENGINEPUB_API MatlabEngine
	{
	public:
		~MatlabEngine();
		static MatlabEngine* getInstancePrt();
		static MatlabEngine& getInstanceObj();

		void initMatlabEngine();

		/* ����CRG���� */
		void loadCrgData(const std::string crgFile);
		bool saveCrgDataToFile(const std::string crgFile);

		Engine* getMatlabEngine() { return matlabEngine; }

		void setCrgMatlabWorkPath(const std::string path);

		/* �������ݳ�ʼ�� */
		//void initCrgDataParamters(int u, int v, double uinc, double vinc, double** data);

	public:
		/* ����CRG����mxArray Struct���� */
		bool createCrgData();

		void setCrgDataParameter(CrgData *data);
		
		/* CRG���ݲ�������:���� */
		bool createCrgCT(const std::string comment);

		bool setCrgDataZ(double **data);

		bool setCrgDataToMatlab();
		//void setDataToMatlab();

		/* CRG���ݲ�������:nu */
		bool setCrgDataNu(double nu);
		
		/* CRG���ݲ�������:nv */
		bool setCrgDataNv(double *nv);

		/* CRG���ݲ�������:uinc */
		bool setCrgDataUinc(double uinc);

		/* CRG���ݲ�������:vinc */
		bool setCrgDataVinc(double vinc);

		/* CRG���ݲ�������:banking */
		bool setCrgDataBanking(double banking);

		/* CRG���ݲ�������:phi */
		bool setCrgDataPhi(double *phi);

		/* CRG���ݲ�������:slope */
		bool setCrgDataSlope(double *slope);

	private:

		void changeMatlabPath(const std::string path);

		void releaseMatlabEngine();

	private:
		MatlabEngine();
		static MatlabEngine* instance;

		Engine* matlabEngine;
		mxArray* pCrgData;
		mxArray* pCrgDataCt;
		mxArray* pCrgDataZ;
		mxArray* pCrgDataV;
		mxArray* pCrgDataU;
		mxArray* pCrgDataBanking;
		mxArray* pCrgDataPhi;
		mxArray* pCrgDataSlope;

		CrgData *crgDataStruct;
		double *crgDataZ;

	};
}
#endif // ! MATLAB_ENGINE_H

