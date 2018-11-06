// JDGC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <MatlabEnginePub/MatlabEngine.h>

#include <time.h>

int main()
{
	std::string path = "D:\\SharperM\\JDGC\\OpenCRG.1.1.2\\matlab";
	MATLABENGINE::MatlabEngine* mEngine = MATLABENGINE::MatlabEngine::getInstancePrt();
	//Engine* ep = mEngine->getMatlabEngine();

	mEngine->setCrgMatlabWorkPath(path);

	path = std::string("Copyright 2005-2010 OpenCRG - Daimler AG - Jochen Rauh");
	double uinc = 0.01;
	double vinc = 0.01;
	int nv = 201;
	int nu = nv * 5; /* 1005 */

	CrgData *pdata = new CrgData();
	pdata->crgDataUInc = 0.01;
	pdata->crgDataVInc = 0.01;
	pdata->crgDataVMax = crgDataNV;
	pdata->crgDataUEnd = 1005;

	/* 创建一个 NU * NV 的二维数组 */
	double **peaks= new double *[nu];
	for (int i = 0; i < nu; i++)
	{
		peaks[i] = new double[nv];
	}

	time_t tm = time(0);
	srand(tm);
	for (int i = 0; i < nu; i++)
	{
		for (int j = 0; j <nv; j++)
		{
			peaks[i][j] = -0.5 + double(rand() % 1000) / 1000.0;
		}
	}
	mEngine->createCrgData();
	mEngine->setCrgDataParameter(pdata);
	mEngine->setCrgDataToMatlab();
	mEngine->setCrgDataZ(peaks);
	
	if (mEngine->createCrgCT(path))
	{
		path = std::string("D:\\SharperM\\JDGC\\data\\crgdata_02.crg");
		mEngine->saveCrgDataToFile(path);
	}
    return 0;
}

