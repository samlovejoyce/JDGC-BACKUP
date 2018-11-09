// JDGC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <time.h>
#include <string>

//#include <MatlabEnginePub/MatlabEngineBase.h>
#include <TerrainElevationDB/DBEngine.h>


int main()
{
	//std::string path = "D:\\SharperM\\JDGC\\OpenCRG.1.1.2\\matlab";
	//MATLABENGINE::MatlabEngine* mEngine = MATLABENGINE::MatlabEngine::getInstancePrt();
	////Engine* ep = mEngine->getMatlabEngine();
	//mEngine->setCrgMatlabWorkPath(path);
	//path = std::string("Copyright 2005-2010 OpenCRG - Daimler AG - Jochen Rauh");
	//double uinc = 0.01;
	//double vinc = 0.01;
	//int nv = 201;
	//int nu = nv * 5;
	//CrgData *pdata = new CrgData();
	//pdata->crgDataUInc = 0.01;
	//pdata->crgDataVInc = 0.01;
	//pdata->crgDataVMax = crgDataNV;
	//pdata->crgDataUEnd = 1005;

	//double **peaks= new double *[nu];
	//for (int i = 0; i < nu; i++)
	//{
		/* 创建一个 NU * NV 的二维数组 */
	//	peaks[i] = new double[nv];
	//}

	//time_t tm = time(0);
	//srand(tm);
	//for (int i = 0; i < nu; i++)
	//{
	//	for (int j = 0; j <nv; j++)
	//	{
	//		peaks[i][j] = -0.5 + double(rand() % 1000) / 1000.0;
	//	}
	//}
	//mEngine->createCrgData();
	//mEngine->setCrgDataParameter(pdata);
	//mEngine->setCrgDataToMatlab();
	//mEngine->setCrgDataZ(peaks);
	//
	//if (mEngine->createCrgCT(path))
	//{
	//	path = std::string("D:\\SharperM\\JDGC\\data\\crgdata_02.crg");
	//	mEngine->saveCrgDataToFile(path);
	//}

	//TerrainElevation::DBEngine *dbEngine = TerrainElevation::DBEngine::getInstance();

	//bool seccessful = dbEngine->connectDB();

	getchar();
    return 0;
}

