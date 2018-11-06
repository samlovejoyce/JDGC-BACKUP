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

		/* 载入CRG数据 */
		void loadCrgData(const std::string crgFile);
		bool saveCrgDataToFile(const std::string crgFile);

		Engine* getMatlabEngine() { return matlabEngine; }

		void setCrgMatlabWorkPath(const std::string path);

		/* 所需数据初始化 */
		//void initCrgDataParamters(int u, int v, double uinc, double vinc, double** data);

	public:
		/* 创建CRG数据mxArray Struct类型 */
		bool createCrgData();

		void setCrgDataParameter(CrgData *data);
		
		/* CRG数据参数设置:声明 */
		bool createCrgCT(const std::string comment);

		bool setCrgDataZ(double **data);

		bool setCrgDataToMatlab();
		//void setDataToMatlab();

		/* CRG数据参数设置:nu */
		bool setCrgDataNu(double nu);
		
		/* CRG数据参数设置:nv */
		bool setCrgDataNv(double *nv);

		/* CRG数据参数设置:uinc */
		bool setCrgDataUinc(double uinc);

		/* CRG数据参数设置:vinc */
		bool setCrgDataVinc(double vinc);

		/* CRG数据参数设置:banking */
		bool setCrgDataBanking(double banking);

		/* CRG数据参数设置:phi */
		bool setCrgDataPhi(double *phi);

		/* CRG数据参数设置:slope */
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

