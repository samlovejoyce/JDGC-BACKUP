#ifndef ME_ROAD_PSD_H
#define ME_ROAD_PSD_H

#include <MatlabEnginePub/Export.h>
#include <MatlabEnginePub/ConnectMatlab.h>

namespace MatlabEngine
{
	/************************************************************************/
	/*	���ܣ�����·�湦�����ܶ�����                                                                     */
	/************************************************************************/
	class MERoadPSD
	{
	public:
		MERoadPSD();
		~MERoadPSD();

		/** ���õ�·�������ܶ�������� */
		void setRoadPSDData();

		void generationData();

	private:
		ConnectMatlab *matlabEngineBase;


	};
}

#endif // !ME_ROAD_PSD_H
