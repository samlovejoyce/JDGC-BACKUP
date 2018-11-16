#ifndef MATLAB_ENGINE_H
#define MATLAB_ENGINE_H

#include <MatlabEnginePub/Export.h>

#include <engine.h>
#include <string>

namespace MatlabEngine {

	class MAMLATENGINEPUB_API MatlabEngineBase
	{
	public:
		~MatlabEngineBase();
		static MatlabEngineBase* getInstancePrt();
		static MatlabEngineBase& getInstanceObj();

		/** ��ʼ��matlab���滷�� */
		void initMatlabEngine();
		
		/** ִ��matlab���� */
		bool runMatlabCommand(const std::string cmd);

		/** ��ȡmatlab��engineָ�� */
		Engine* getMatlabEngine() { return matlabEngine; }

		/** �ر�matlab�������л��� */
		void closeMatlabEngine();

	private:
		MatlabEngineBase();
		static MatlabEngineBase* instance;

		Engine* matlabEngine;
	};
}
#endif // ! MATLAB_ENGINE_H

