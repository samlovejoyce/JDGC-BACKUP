#ifndef DATABASE_H
#define DATABASE_H

#include <MySQLLib/Export.h>

#include <iostream>
#include <fstream>
#include <string>
#include <mysql.h>

namespace MYSQLDB
{
	class MYSQLLIB_API Database
	{
	public:
		Database(const std::string &host, const std::string& user, const std::string &password, const std::string &database, unsigned int port, const char *unixSocket, unsigned long clientFlag);
		Database();
		Database(const Database &db);
		virtual ~Database();

		static void libraryInitialize(bool embedded);
		static void threadInitialize();

		static void libraryFinalize();
		static void threadFinalize();

		void setInitialCommand(const std::string &initialCommand);
		bool autoCommit() const;
		void autoCommit(bool value);
		void connect();

		void startTransaction();
		void commit();
		void rollback();
		void useDatabase(const std::string &dbName);
		int execute(const std::string &statement);
		void source(const std::string &fileName);

		bool isConnected();

	private:
		MYSQL *_db;

		std::string _host;
		std::string _user;
		std::string _password;
		std::string _database;
		std::string _initialCommand;
		unsigned int _port;
		const char *_unixSocket;
		unsigned long _clientFlag;

		bool _isConnected;
		bool _autocommit;

		static bool _embedded;
	};

	class LibraryInitializer
	{
	public:
		LibraryInitializer(bool embedded);
		~LibraryInitializer();
	};

	class ThreadInitializer
	{
	public:
		ThreadInitializer();
		~ThreadInitializer();
	};
}

#endif // !DATABASE_H
