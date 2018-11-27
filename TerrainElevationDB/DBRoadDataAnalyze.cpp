#include <TerrainElevationDB/DBRoadDataAnalyze.h>

TerrainElevation::DBRoadDataAnalyze::DBRoadDataAnalyze()
	:readDataInstance(nullptr)
	,roadDataBlob(nullptr)
{
	readDataInstance = new DBReadRoadDataFromSql();
	roadDataBlob = new RoadDataBlobStruct();
}

TerrainElevation::DBRoadDataAnalyze::~DBRoadDataAnalyze()
{
	if (readDataInstance)
		delete readDataInstance;
	
	if (roadDataBlob)
		delete roadDataBlob;
}

void TerrainElevation::DBRoadDataAnalyze::roadPointsInterp(std::vector<Pointf>& vecPoints)
{
	float resolution = 0.005;

	float xbeg = (*vecPoints.begin()).x;
	float xend = (*(vecPoints.end() - 1)).x;

	/** ����x��resolutionΪ�������xbeg��xend֮���ж��ٸ����� */
	int num = int((xend - xbeg) / resolution);

	std::vector<float> xData, yData;
	std::vector<Pointf>::iterator it = vecPoints.begin();
	for (it; it != vecPoints.end(); it++)
	{
		xData.push_back(it->x);
		yData.push_back(it->y);
	}

	std::vector<float> xvals, yvals;
	for (int i = 0; i < num; i++)
		xvals.push_back(xbeg + i * resolution);

	for (float xi : xvals)
	{
		float y = Math::interpolate(xData, yData, xi);

		yvals.push_back(y);
	}
	
	vecPoints.clear();
	for (int i = 0; i < num; i++)
	{
		vecPoints.push_back(Pointf(xvals[i], yvals[i]));
	}
	
	getRoadData(vecPoints);
}

void TerrainElevation::DBRoadDataAnalyze::getRoadData(std::vector<Pointf>& vecPoints)
{
	if (vecPoints.empty())
		return;
	std::vector<Pointf>::iterator it = vecPoints.begin();
	for (it; it != vecPoints.end(); it++)
	{
		/** �ж����ݿ����Ƿ������ݣ����û�У�������ݿ��ж�ȡ */
		if (isRoadDataBlobEmpty())
		{
			readCurrentPointBlob(*it);
		}
		
		/** 
		 * �ж���ǰ���Ƿ������ݿ��ڣ��������ȡ�õ��zֵ�������ڣ�
		 * ������ݿ��ж�ȡ�õ��������ݿ�����ݣ�����ȡ�õ��zֵ��
		 */
		if (currentPointIsInBlob(*it))
			getZValue(*it);
		else
		{
			readCurrentPointBlob(*it);
			getZValue(*it);
		}
	}
	
}

void TerrainElevation::DBRoadDataAnalyze::getZValue(Pointf & point)
{
	int i = 0, j = 0;
	float resolution = 0.005;

	while (true)
	{
		if (roadDataBlob->xmin + i * resolution > point.x)
			break;
		i++;
	}
	while (true)
	{
		if (roadDataBlob->ymin + j * resolution > point.y)
			break;
		j++;
	}

	point.z += roadDataBlob->zdata[i * 100 + j];
}

bool TerrainElevation::DBRoadDataAnalyze::isRoadDataBlobEmpty()
{
	return roadDataBlob->isEmpty();
}

bool TerrainElevation::DBRoadDataAnalyze::currentPointIsInBlob(Pointf & point)
{

	return (roadDataBlob->xmin <= point.x) && (roadDataBlob->xmax > point.x) && (roadDataBlob->ymin <= point.y) && (roadDataBlob->ymax > point.y);
}

void TerrainElevation::DBRoadDataAnalyze::readCurrentPointBlob(Pointf & point)
{
	roadDataBlob->setData(point);

	if (readDataInstance != nullptr)
	{
		float *zdata;
		zdata = readDataInstance->readData(roadDataBlob->xmin, roadDataBlob->xmax, roadDataBlob->ymin, roadDataBlob->ymax);
		memcpy(roadDataBlob->zdata, zdata, sizeof(float) * DB_BLOB_SIZE);
	}
}
