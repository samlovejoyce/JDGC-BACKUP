#ifndef ME_ROAD_PSD_H
#define ME_ROAD_PSD_H

#include <MatlabEnginePub/Export.h>
#include <MatlabEnginePub/ConnectMatlab.h>
#include <MatlabEnginePub/CMatlab.h>

#include <matrix.h>

namespace MatlabEngine
{
	/************************************************************************/
	/*	���ܣ�����·�湦�����ܶ�����                                                                     */
	/************************************************************************/
	class RoadPSD
	{
	public:
		RoadPSD();
		~RoadPSD();

		/** ���õ�·�������ܶ�������� */
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
