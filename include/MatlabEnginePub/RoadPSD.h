#ifndef ME_ROAD_PSD_H
#define ME_ROAD_PSD_H

#include <MatlabEnginePub/Export.h>
#include <MatlabEnginePub/ConnectMatlab.h>
#include <MatlabEnginePub/CMatlab.h>

#include <matrix.h>

namespace MatlabEngine
{
	/************************************************************************/
	/*	功能：生成路面功率谱密度数据                                                                     */
	/************************************************************************/
	class RoadPSD
	{
	public:
		RoadPSD();
		~RoadPSD();

		/** 设置道路功率谱密度所需参数 */
		void setRoadPSDData();

		void generationData();

	private:
		ConnectMatlab *_connenctMatlab;
		CMatlab *_matlab;

		mxArray *_a1;
		mxArray *_a2;
		mxArray *_a3;
		mxArray *_a4;
	};
}

#endif // !ME_ROAD_PSD_H
