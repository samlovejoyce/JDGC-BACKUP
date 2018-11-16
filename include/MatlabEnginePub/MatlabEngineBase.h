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

		/** 初始化matlab引擎环境 */
		void initMatlabEngine();
		
		/** 执行matlab命令 */
		bool runMatlabCommand(const std::string cmd);

		/** 获取matlab的engine指针 */
		Engine* getMatlabEngine() { return matlabEngine; }

		/** 关闭matlab引擎运行环境 */
		void closeMatlabEngine();

	private:
		MatlabEngineBase();
		static MatlabEngineBase* instance;

		Engine* matlabEngine;
	};
}
#endif // ! MATLAB_ENGINE_H

