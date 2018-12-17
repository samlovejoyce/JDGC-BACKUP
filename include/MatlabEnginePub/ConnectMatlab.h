#ifndef MATLAB_ENGINE_H
#define MATLAB_ENGINE_H

#include <MatlabEnginePub/Export.h>

#include <engine.h>
#include <string>

namespace MatlabEngine {

	class MAMLATENGINEPUB_API ConnectMatlab
	{
		ConnectMatlab();
	public:
		~ConnectMatlab();

	public:

		static ConnectMatlab *getInstance();
		/** 初始化matlab引擎环境 */
		bool openMatlabEngine();
		
		/** 关闭matlab引擎运行环境 */
		void closeMatlabEngine(); 
		
		/** 执行matlab命令 */
		bool runMatlabCmd(const std::string cmd);

		bool putVariable(const std::string name, const mxArray *mx);
		mxArray* getVariable(const std::string name);
		
		/** 获取matlab的engine指针 */
		Engine* getMatlabEngine() { return _engine; }
	private:
		static ConnectMatlab *_instance;
		Engine* _engine;
	};
}
#endif // ! MATLAB_ENGINE_H

