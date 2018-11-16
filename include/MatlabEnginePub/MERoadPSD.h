#ifndef ME_ROAD_PSD_H
#define ME_ROAD_PSD_H

#include <MatlabEnginePub/Export.h>
#include <MatlabEnginePub/MatlabEngineBase.h>

namespace MatlabEngine
{
	/************************************************************************/
	/*	功能：生成路面功率谱密度数据                                                                     */
	/************************************************************************/
	class MERoadPSD
	{
	public:
		MERoadPSD();
		~MERoadPSD();

		/** 设置道路功率谱密度所需参数 */
		void setRoadPSDData();

		void generationData();

	private:
		MatlabEngineBase *matlabEngineBase;


	};
}

#endif // !ME_ROAD_PSD_H
