
#ifndef DBROADDATAANALYZE_H
#define DBROADDATAANALYZE_H

#include <TerrainElevationDB/Export.h>
#include <TerrainElevationDB/CommDefine.h>
#include <TerrainElevationDB/DatabaseRead.h>

#include <vector>


namespace TerrainElevation
{
	/**
	 * 主要功能：根据一系列输入的点获取这些输入点的高程，
	 * 所有数据存储在数据库中
	 */
	class TERRAINELEVATIONDB_API RoadCenterLine
	{
	public:
		RoadCenterLine();
		~RoadCenterLine();

		/** 对给定的一系列点进行线性插值 */
		void roadPointsInterp(std::vector<Pointf> &vecPoints);

		/** 获取给定系列坐标的z值 */
		void getRoadCenterLineData(std::vector<Pointf> &vecPoints);

	protected:
		/** 给定x，y，获取其对应的z值 */
		void getZValue(Pointf &point);

		/** 数据块内是否有数据 */
		bool isRoadDataBlobEmpty();

		/** 当前点是否在数据块内 */
		bool currentPointIsInBlob(Pointf &point);

		/** 从数据库中提取当前点所在的数据块 */
		void readCurrentPointBlob(Pointf &point);

	private:
		DatabaseRead *readDataInstance;
		RoadDataBlobStruct *roadDataBlob;

		std::vector<Pointf> vPointf;
	};
}

#endif // !DBROADDATAANALYZE_H
