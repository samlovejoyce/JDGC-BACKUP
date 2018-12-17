#include "MatlabEnginePub/ConnectMatlab.h"


using namespace MatlabEngine;

ConnectMatlab *ConnectMatlab::_instance = nullptr;

ConnectMatlab::ConnectMatlab()
	:_engine(nullptr)
{
}

ConnectMatlab::~ConnectMatlab()
{
	closeMatlabEngine();
}

ConnectMatlab * MatlabEngine::ConnectMatlab::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ConnectMatlab();
	}
	return _instance;
}

bool ConnectMatlab::openMatlabEngine()
{
	if (!_engine)
	{
		_engine = engOpen(nullptr);
		/* ����Matlab�����д��� */
		engSetVisible(_engine, true);
	}
	return true;
}

bool MatlabEngine::ConnectMatlab::runMatlabCmd(const std::string cmd)
{
	if(engEvalString(_engine, cmd.c_str()) !=0 )
		return false;

	return true;
}

bool ConnectMatlab::putVariable(const std::string name, const mxArray * mx)
{
	if( engPutVariable(_engine, name.c_str(), mx) != 0)
		return false;
	return true;
}

mxArray *ConnectMatlab::getVariable(const std::string name)
{
	mxArray *mx = nullptr;
	mx = engGetVariable(_engine, name.c_str());
	if (!mx)
		return nullptr;
	return mx;
}

void ConnectMatlab::closeMatlabEngine()
{
	if (_engine)
	{
		engClose(_engine);
		_engine = nullptr;
	}
}

