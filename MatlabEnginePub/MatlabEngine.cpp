#include "MatlabEnginePub/MatlabEngine.h"


using namespace MATLABENGINE;

MatlabEngine* MatlabEngine::instance = nullptr;

void MatlabEngine::setCrgMatlabWorkPath(const std::string path)
{
	changeMatlabPath(path);

	engEvalString(matlabEngine, "crg_init;");
}

void MatlabEngine::changeMatlabPath(const std::string path)
{
	std::string str = "cd ";
	str = str + path + ";";
	engEvalString(matlabEngine, str.c_str());
}

bool MATLABENGINE::MatlabEngine::setCrgDataToMatlab()
{
	if (!pCrgData )
	{
		return false;		
	}

	mxArray *pNv = mxCreateDoubleScalar(crgDataNV);
	engPutVariable(matlabEngine, "nv", pNv);

	mxArray *pNu = mxCreateDoubleScalar(crgDataStruct->crgDataUEnd);
	engPutVariable(matlabEngine, "nu", pNu);
	
	mxArray *pUinc = mxCreateDoubleScalar(crgDataStruct->crgDataUInc);
	engPutVariable(matlabEngine, "uinc", pUinc);
	
	mxArray *pVinc = mxCreateDoubleScalar(crgDataStruct->crgDataVInc);
	engPutVariable(matlabEngine, "vinc", pVinc);

	/* 设置临时v值 */
	pCrgDataV = mxCreateDoubleMatrix(1, crgDataNV, mxREAL);
	double *tempvalue = new double[crgDataNV - 1];
	for (int i = 0; i < crgDataNV; i++)
	{
		tempvalue[i] = i * crgDataStruct->crgDataVInc - crgDataStruct->crgDataVMax;
	}

	double *temp = mxGetPr(pCrgDataV);
	memcpy(temp, tempvalue, crgDataNV * sizeof(double));
	if (engPutVariable(matlabEngine, CRG_DATA_V, pCrgDataV) != 0)
		return false;

	/* ======================== 设置data的数据 ================================ */

	/* 设置data.u的数据 */
	pCrgDataU = mxCreateDoubleScalar((crgDataStruct->crgDataUEnd - 1) * crgDataStruct->crgDataUInc);
	mxSetField(pCrgData, 0, CRG_DATA_U, pCrgDataU);

	/* 设置data.v的数据 */
	pCrgDataV = mxCreateDoubleScalar((crgDataStruct->crgDataVMax - 1) * crgDataStruct->crgDataVInc / 2);
	mxSetField(pCrgData, 0, CRG_DATA_V, pCrgDataV);

	/* 设置data.b的数据*/
	pCrgDataBanking = mxCreateDoubleScalar(0);
	mxSetField(pCrgData, 0, CRG_DATA_B, pCrgDataBanking);

	/* 设置data.b的数据*/
	pCrgDataPhi = mxCreateDoubleScalar(0);
	mxSetField(pCrgData, 0, CRG_DATA_P, pCrgDataPhi);

	/* 设置data.b的数据*/
	pCrgDataSlope = mxCreateDoubleScalar(0);
	mxSetField(pCrgData, 0, CRG_DATA_S, pCrgDataSlope);

	if (engPutVariable(matlabEngine, CRG_DATA, pCrgData) != 0)
		return false;

	mxDestroyArray(pNu);
	mxDestroyArray(pNv);
	mxDestroyArray(pUinc);
	mxDestroyArray(pVinc);

	return true;
}

//void MATLABENGINE::MatlabEngine::initCrgDataParamters(int u, int v, double uinc, double vinc, double** data)
//{
//	crgDataNu = u;
//	crgDataNv = v;
//	crgDataVInc = vinc;
//	crgDataUInc = uinc;
//	crgDataZRows = getRows();
//	crgDataZColumns = getColums();
//
//	crgDataZ = new double [crgDataZRows * crgDataZColumns];
//	for (int i = 0; i < crgDataZColumns; i++)
//	{
//		for (int j = 0; j < crgDataZRows; j++)
//		{
//			crgDataZ[i * crgDataZRows + j] = data[j][i];
//		}
//	}
//}

bool MATLABENGINE::MatlabEngine::createCrgData()
{
	if (pCrgData == nullptr)
	{
		int ndim = 1;
		size_t dims[] = { 1, 1 };
		pCrgData = mxCreateStructArray(ndim, dims, crgDataFiledLength, crgDataFiledName);				
	}
	if (engPutVariable(matlabEngine, CRG_DATA, pCrgData) != 0)
	{
		return false;
	}
	return true;
}

bool MATLABENGINE::MatlabEngine::createCrgCT(const std::string comment)
{
	mxArray *tempStr = nullptr;

	if (pCrgDataCt == nullptr)
	{
		/* 创建mxString型变量 */
		pCrgDataCt = mxCreateCellMatrix(1, 1);
	}

	tempStr = mxCreateString(comment.c_str());
	mxSetCell(pCrgDataCt, 0, tempStr);

	/* 给mxComment变量赋值 */
	mxSetField(pCrgData, 0, CRG_DATA_CT, pCrgDataCt);

	if (engPutVariable(matlabEngine, CRG_DATA, pCrgData) != 0)
		return false;
	mxDestroyArray(tempStr);

	return true;
}

void MATLABENGINE::MatlabEngine::setCrgDataParameter(CrgData * data)
{
	crgDataStruct = data;
}

bool MATLABENGINE::MatlabEngine::setCrgDataZ(double ** data)
{
	if (!pCrgData)
		return false;

	crgDataZ = new double[(int)crgDataStruct->crgDataUEnd * crgDataNV];
	for (int i = 0; i < crgDataNV; i++)
	{
		for (int j = 0; j < (int)crgDataStruct->crgDataUEnd; j++)
		{
			crgDataZ[i * (int)crgDataStruct->crgDataUEnd + j] = data[j][i];
		}
	}

	/* 设置data.z的数据 */
	pCrgDataZ = mxCreateDoubleMatrix((int)crgDataStruct->crgDataUEnd, crgDataNV, mxREAL);
	if (engPutVariable(matlabEngine, CRG_DATA_Z, pCrgDataZ) != 0)
		return false;

	double *tempZ = (double *)mxGetPr(pCrgDataZ);
	memcpy(tempZ, crgDataZ, (int)crgDataStruct->crgDataUEnd * crgDataNV * sizeof(double));

	if (engPutVariable(matlabEngine, CRG_DATA_Z, pCrgDataZ) == 0)
		mxSetField(pCrgData, 0, CRG_DATA_Z, pCrgDataZ);
	else
		return false;

	/* 更新data的数据 */
	if (engPutVariable(matlabEngine, CRG_DATA, pCrgData) != 0)
		return false;

	return true;
}

bool MATLABENGINE::MatlabEngine::setCrgDataNu(double nu)
{
	if (!pCrgData)
		return false;
	
	mxArray *pNu = mxCreateDoubleScalar(nu);
	if( engPutVariable(matlabEngine, "nu", pNu) != 0)
		return false;
	mxDestroyArray(pNu);

	return true;
}

bool MATLABENGINE::MatlabEngine::setCrgDataNv(double * nv)
{
	return false;
}

bool MATLABENGINE::MatlabEngine::setCrgDataUinc(double uinc)
{
	return false;
}

bool MATLABENGINE::MatlabEngine::setCrgDataVinc(double vinc)
{
	return false;
}

bool MATLABENGINE::MatlabEngine::setCrgDataBanking(double banking)
{
	return false;
}

bool MATLABENGINE::MatlabEngine::setCrgDataPhi(double * phi)
{
	return false;
}

bool MATLABENGINE::MatlabEngine::setCrgDataSlope(double * slope)
{
	return false;
}


MatlabEngine::MatlabEngine()
	:matlabEngine(nullptr)
	,pCrgData(nullptr)
	,pCrgDataCt(nullptr)
	,pCrgDataU(nullptr)
	,pCrgDataV(nullptr)
	,pCrgDataZ(nullptr)
	,pCrgDataPhi(nullptr)
{
	initMatlabEngine();
}


MatlabEngine::~MatlabEngine()
{
	releaseMatlabEngine();
}

MatlabEngine * MatlabEngine::getInstancePrt()
{
	if (instance == nullptr)
	{
		instance = new MatlabEngine();
	}
	return instance;
}

MatlabEngine& MatlabEngine::getInstanceObj()
{
	if (instance == nullptr)
	{
		instance = new MatlabEngine();
	}
	return (*instance);
}

void MatlabEngine::initMatlabEngine()
{
	matlabEngine = engOpen(nullptr);
	if (matlabEngine)
	{
		/* 隐藏Matlab命令行窗口 */
		engSetVisible(matlabEngine, true);
	}
	else
	{
		matlabEngine = nullptr;
	}
	
}

void MatlabEngine::releaseMatlabEngine()
{
	if (matlabEngine)
	{
		mxDestroyArray(pCrgData);
		mxDestroyArray(pCrgDataCt);
		mxDestroyArray(pCrgDataZ);
		mxDestroyArray(pCrgDataV);
		mxDestroyArray(pCrgDataU);
		mxDestroyArray(pCrgDataPhi);

		for (int i = 0; i < (int)crgDataStruct->crgDataUEnd * crgDataNV; i ++)
		{
			delete[] crgDataZ;
		}
	
		engClose(matlabEngine);
		matlabEngine = nullptr;
	}
}

void MatlabEngine::loadCrgData(const std::string crgFile)
{
	std::string command;
	std::string variableName = "data";
	command = variableName + " = crg_read( \'" + crgFile + "\');";

	if (engEvalString(matlabEngine, command.c_str()) == 0)
	{
		pCrgData = engGetVariable(matlabEngine, variableName.c_str());
	}
}

bool MATLABENGINE::MatlabEngine::saveCrgDataToFile(const std::string crgFile)
{
	std::string command = CRG_DATA;

	command = "ans = crg_single(" + command + ");";
	if (engEvalString(matlabEngine, command.c_str()) != 0)
	{
		return false;
	}
	command = CRG_DATA;
	command = "crg_write(ans, \'" + crgFile + "\');";
	if (engEvalString(matlabEngine, command.c_str()) != 0)
	{
		return false;
	}
	return true;
}
