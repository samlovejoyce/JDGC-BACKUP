// JDGC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <ctime>
#include <iostream>
#include <string>

#include <mysql.h>

//#include <MatlabEnginePub/MatlabEngineBase.h>
//#include <TerrainElevationDB/DBMysqlEngine.h>
//#include <TerrainElevationDB/DBWriteRoadDataToSql.h>

//#include <TerrainElevationDB/DBGenerationData.h>
#include <TerrainElevationDB/RoadElevationDataExtraction.h>

int main()
{

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

	/** 生成试车场路面点云数据 */
	/*TerrainElevation::DBGenerationData *gdata = new TerrainElevation::DBGenerationData();
	gdata->generateRoadData();*/


	/** 访问数据库，获取一系列点的高程 */
	TerrainElevation::RoadElevationDataExtraction *roadDataAnalyze = new TerrainElevation::RoadElevationDataExtraction();
	
	std::vector<Pointf> vecPoint;
	vecPoint.push_back(Pointf(15.0, 119.3));
	vecPoint.push_back(Pointf(60.0, 125.4));
	
	SYSTEMTIME stNow;
	GetSystemTime(&stNow);

	std::cout << "Start:" << stNow.wMinute << ":" << stNow.wSecond << ":" << stNow.wMilliseconds << std::endl;
	roadDataAnalyze->roadPointsInterp(vecPoint);
	GetSystemTime(&stNow);
	std::cout << "End:" << stNow.wMinute << ":" << stNow.wSecond << ":" << stNow.wMilliseconds << std::endl;

	getchar();
    return 0;
}
