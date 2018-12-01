#include <TerrainElevationDB/CommDefine.h>

float Math::interpolate(std::vector<float> &xData, std::vector<float> &yData, float xi)
{
	int size = xData.size();

	int i = 0;																		// find left end of interval for interpolation
	if (xi >= xData[size - 2])														// special case: beyond right end
	{
		i = size - 2;
	}
	else
	{
		while (xi > xData[i + 1]) i++;
	}

	float xL = xData[i], yL = yData[i], xR = xData[i + 1], yR = yData[i + 1];		// points on either side (unless beyond ends)

	/*if (!extrapolate)
	{
		if (xi < xL) yR = yL;
		if (xi > xR) yL = yR;
	}*/
	double dydx = (yR - yL) / (xR - xL);											// gradient

	return yL + dydx * (xi - xL);													// linear interpolation

}

void RoadDataBlobStruct::setData(Pointf & point)
{
	int i = 0, j = 0;
	float resolution = 0.5;
	float tempxmin, tempxmax;
	float tempymin, tempymax;

	while (true)
	{
		tempxmin = abs(point.x) - i * resolution;
		tempxmax = abs(point.x) - (i + 1) * resolution;

		if ((tempxmin >= 0.0) && (tempxmax < 0.0))
			break;
		i++;
	}
	while (true)
	{
		tempymin = abs(point.y) - j * resolution;
		tempymax = abs(point.y) - (j + 1) * resolution;

		if ((tempymin >= 0.0) && (tempymax < 0.0))
			break;
		j++;
	}

	/** 确定最大/最小值 */
	if (point.x >= 0.0)
	{
		xmin = i * resolution;
		xmax = (i + 1) * resolution;
	}
	else
	{
		xmin = -((i + 1) * resolution);
		xmax = -(i * resolution);
	}
	if (point.y >= 0.0)
	{
		ymin = j *resolution;
		ymax = (j + 1) * resolution;
	}
	else
	{
		ymin = -((j + 1) * resolution);
		ymax = -(j * resolution);
	}
}

bool RoadDataBlobStruct::isEmpty()
{
	if ((xmin != xmax) || (ymin != ymax))
		return false;
	
	return true;
}