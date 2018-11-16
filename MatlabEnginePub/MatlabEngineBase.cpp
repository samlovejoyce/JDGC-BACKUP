#include "MatlabEnginePub/MatlabEngineBase.h"


using namespace MatlabEngine;

MatlabEngineBase* MatlabEngineBase::instance = nullptr;

MatlabEngineBase::MatlabEngineBase()
	:matlabEngine(nullptr)
{
	initMatlabEngine();
}


MatlabEngineBase::~MatlabEngineBase()
{
	closeMatlabEngine();
}

MatlabEngineBase * MatlabEngineBase::getInstancePrt()
{
	if (instance == nullptr)
	{
		instance = new MatlabEngineBase();
	}
	return instance;
}

MatlabEngineBase& MatlabEngineBase::getInstanceObj()
{
	if (instance == nullptr)
	{
		instance = new MatlabEngineBase();
	}
	return (*instance);
}

void MatlabEngineBase::initMatlabEngine()
{
	matlabEngine = engOpen(nullptr);
	if (matlabEngine)
	{
		/* Òþ²ØMatlabÃüÁîÐÐ´°¿Ú */
		engSetVisible(matlabEngine, true);
	}
	else
	{
		matlabEngine = nullptr;
	}
}

bool MatlabEngine::MatlabEngineBase::runMatlabCommand(const std::string cmd)
{
	if(engEvalString(matlabEngine, cmd.c_str()) !=0 )
		return false;

	return true;
}

void MatlabEngineBase::closeMatlabEngine()
{
	if (matlabEngine)
	{
		engClose(matlabEngine);
		matlabEngine = nullptr;
	}
}

