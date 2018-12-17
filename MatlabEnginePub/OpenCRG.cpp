#include <MatlabEnginePub/OpenCRG.h>

namespace MatlabEngine
{
	OpenCRG::OpenCRG()
	{
		_connectMatlab = ConnectMatlab::getInstance();
		_matlab = new CMatlab();
		_data = nullptr;
	}

	OpenCRG::~OpenCRG()
	{
		if (_matlab)
			delete _matlab;
	}

	bool OpenCRG::setWorkPath(std::string path)
	{
		if(!_connectMatlab->openMatlabEngine())
		{
			return false;
		}
		else
		{
			std::string cmd;
			cmd = "cd " + path + ";";

			if (!_connectMatlab->runMatlabCmd(cmd))
				return false;
		}
		return true;
	}

	bool OpenCRG::initOpenCRGLibEnv()
	{
		std::string cmd;
		cmd = "crg_init;";

		if(!_connectMatlab->runMatlabCmd(cmd))
			return false;
		return true;
	}
	void OpenCRG::setOpenCRGData(CurveData * data)
	{
		if (_data)
			delete _data;
		
		_data = data;
	}
	void OpenCRG::setComment(const std::string commnet)
	{
		_comment = _matlab->createString(commnet);
	}

	void OpenCRG::setParmaterToMatlab()
	{
		if (!_CRGDataStruct)
		{
			int ndim = 1;
			size_t dims[] = { 1, 1 };
			_CRGDataStruct = _matlab->createStructArray(ndim, dims, CRG_DATA_FILED_LENGTH, crgDataFiledName);
		}
		_connectMatlab->putVariable(CRG_DATA, _CRGDataStruct);


	}

	void OpenCRG::setIncArray()
	{
		_inc = _matlab->createDoubleScalar(_data->uinc);
	}

	void OpenCRG::setUArray()
	{
		_u = _matlab->createDoubleMatrix(1, 2);
		float *tempData = new float[2];
		tempData[0] = _data->uben;
		tempData[1] = _data->uend;

		_matlab->setData(_u, tempData);
	}

	void OpenCRG::setVArray()
	{
		int i = 0;
		float start = _data->vben;
		while (true)
		{
			if(start + i * _data->vinc >= _data->vend )
				break;
			i++;
		}
		_v = _matlab->createDoubleMatrix(1, i + 1);

		float *tempData = new float[i + 1];
		for (int j = 0; j < i + 1; j++)
		{
			tempData[i] = start + j * _data->vinc;
		}
		_matlab->setData(_v, tempData);

	}
	void OpenCRG::setCurveArray()
	{
		int size = _data->curve.size();
		_curve = _matlab->createCellMatrix(size, 2);
		for (int i = 0; i < size; i++)
		{
			mxArray *tempValue = _matlab->createDoubleScalar(_data->curve.at(i).length);
			_matlab->setCell(_curve, 0, tempValue);

			mxArray *tempCell = _matlab->createCellMatrix(1, 2);
			tempValue = _matlab->createDoubleScalar(_data->curve.at(i).radiusStart);
			_matlab->setCell(tempCell, 0, tempValue);
			tempValue = _matlab->createDoubleScalar(_data->curve.at(i).radiusEnd);
			_matlab->setCell(tempCell, 1, tempValue);

			_matlab->setCell(_curve, 1, tempCell);
		}

	}
	void OpenCRG::setSlopeArray()
	{
		int size = _data->slope.size();
		_slope = _matlab->createCellMatrix(size, 2);
		for (int i = 0; i < size; i++)
		{
			mxArray *tempValue = _matlab->createDoubleScalar(_data->slope.at(i).length);
			_matlab->setCell(_slope, 0, tempValue);

			mxArray *tempCell = _matlab->createCellMatrix(1, 2);
			tempValue = _matlab->createDoubleScalar(_data->slope.at(i).radiusStart);
			_matlab->setCell(tempCell, 0, tempValue);
			tempValue = _matlab->createDoubleScalar(_data->slope.at(i).radiusEnd);
			_matlab->setCell(tempCell, 1, tempValue);

			_matlab->setCell(_slope, 1, tempCell);
		}
	}
	void OpenCRG::setBankkingArray()
	{
		int size = _data->banking.size();
		_bankking = _matlab->createCellMatrix(size, 2);
		for (int i = 0; i < size; i++)
		{
			mxArray *tempValue = _matlab->createDoubleScalar(_data->banking.at(i).length);
			_matlab->setCell(_bankking, 0, tempValue);

			mxArray *tempCell = _matlab->createCellMatrix(1, 2);
			tempValue = _matlab->createDoubleScalar(_data->banking.at(i).radiusStart);
			_matlab->setCell(tempCell, 0, tempValue);
			tempValue = _matlab->createDoubleScalar(_data->banking.at(i).radiusEnd);
			_matlab->setCell(tempCell, 1, tempValue);

			_matlab->setCell(_bankking, 1, tempCell);
		}
	}

	void OpenCRG::setZData()
	{
		int usize = 0, vsize = 0;
		while (true)
		{
			if(_data->uben + usize * _data->uinc >= _data->uend)
				break;
			usize++;
		}
		usize++;
		while (true)
		{
			if(_data->vben + vsize * _data->vinc >= _data->vend)
				break;
			vsize++;
		}
		vsize++;

		_zData = _matlab->createDoubleMatrix(usize, vsize);

		/** апсеох */
		float *tempData = _matlab->getPReal(_zData);
		memcpy(tempData, _data->zData, sizeof(float) * usize * vsize);
	}

	void OpenCRG::save(std::string path, CRGDATATYPE type)
	{
		std::string cmd;
		cmd = "data = crg_write(crg_single(data), '" + path + "', ";

		switch (type)
		{
		case KRBI:
			cmd = cmd + "'KRBI');";
			break;
		case KDBI:
			cmd = cmd + "'KDBI');";
			break;
		case LRFI:
			cmd = cmd + "'LRFI');";
			break;
		case LDFI:
			cmd = cmd + "'LDFI');";
			
			break;
		default:
			break;
		}
		_connectMatlab->runMatlabCmd(cmd);
	}
}