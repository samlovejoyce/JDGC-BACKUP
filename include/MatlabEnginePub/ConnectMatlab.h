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
		/** ��ʼ��matlab���滷�� */
		bool openMatlabEngine();
		
		/** �ر�matlab�������л��� */
		void closeMatlabEngine(); 
		
		/** ִ��matlab���� */
		bool runMatlabCmd(const std::string cmd);

		bool putVariable(const std::string name, const mxArray *mx);
		mxArray* getVariable(const std::string name);
		
		/** ��ȡmatlab��engineָ�� */
		Engine* getMatlabEngine() { return _engine; }
	private:
		static ConnectMatlab *_instance;
		Engine* _engine;
	};
}
#endif // ! MATLAB_ENGINE_H

