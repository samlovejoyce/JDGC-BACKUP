
#ifndef DBROADDATAANALYZE_H
#define DBROADDATAANALYZE_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/DatabaseRead.h>

#include <vector>


namespace TerrainElevation
{
	/**
	 * ��Ҫ���ܣ�����һϵ������ĵ��ȡ��Щ�����ĸ̣߳�
	 * �������ݴ洢�����ݿ���
	 */
	class TERRAINELEVATIONDB_PAI RoadElevationDataExtraction
	{
	public:
		RoadElevationDataExtraction();
		~RoadElevationDataExtraction();

		/** �Ը�����һϵ�е�������Բ�ֵ */
		void roadPointsInterp(std::vector<Pointf> &vecPoints);

		/** ��ȡ����ϵ�������zֵ */
		void getRoadData(std::vector<Pointf> &vecPoints);

	protected:
		/** ����x��y����ȡ���Ӧ��zֵ */
		void getZValue(Pointf &point);

		/** ���ݿ����Ƿ������� */
		bool isRoadDataBlobEmpty();

		/** ��ǰ���Ƿ������ݿ��� */
		bool currentPointIsInBlob(Pointf &point);

		/** �����ݿ�����ȡ��ǰ�����ڵ����ݿ� */
		void readCurrentPointBlob(Pointf &point);

	private:
		DatabaseRead *readDataInstance;
		RoadDataBlobStruct *roadDataBlob;

		std::vector<Pointf> vPointf;
	};
}

#endif // !DBROADDATAANALYZE_H
