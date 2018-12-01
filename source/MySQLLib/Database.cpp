#include <MySQLLib/Database.h>
#include <MySQLLib/DatabaseException.h>

#include <algorithm>
#include <functional>
#include <cctype>

namespace MYSQLDB
{
	
	bool Database::_embedded;

	Database::Database(const std::string & host, const std::string & user, const std::string & password, 
		const std::string & database, unsigned int port, const char * unixSocket, unsigned long clientFlag)
	{
		_host = host;
		_user = user;
		_password = password;
		_database = database;
		_port = port;
		_unixSocket = unixSocket;
		_clientFlag = clientFlag;

		_initialCommand = "";
		_isConnected = false;
		_autocommit = true;

		if ((_db = mysql_init(NULL) ) == NULL)
			throw DatabaseException("Error tryng to initialize MYSQL database", 0, "------", "insufficient memory");

	}

	Database::Database()
	{
		_host = "";
		_user = "";
		_password = "";
		_database = "";
		_port = 0;
		_unixSocket = NULL;
		_clientFlag = 0;
		_initialCommand = "";
		_isConnected = false;
		_autocommit = true;

		if ((_db = mysql_init(NULL)) == NULL)
			throw DatabaseException("Error tryng to initialize MYSQL database", 0, "------", "insufficient memory");

		/* 嵌入式数据库 */
		if (_embedded)
		{
			mysql_options(_db, MYSQL_READ_DEFAULT_GROUP, "embedded");
			//mysql_options(_db, MYSQL_OPT_USE_EMBEDDED_CONNECTION, NULL);
		}
	}

	Database::Database(const Database & db)
	{
		_host = db._host;
		_user = db._user;
		_password = db._password;
		_database = db._database;
		_port = db._port;
		_unixSocket = db._unixSocket;
		_clientFlag = db._clientFlag;

		_initialCommand = db._initialCommand;
		_isConnected = db._isConnected;
		_autocommit = db._autocommit;

		if ((_db = mysql_init(NULL)) == NULL)
			throw DatabaseException("Error tryng to initialize MYSQL database", 0, "------", "insufficient memory");

		if (db._isConnected )
		{
			try
			{
				connect();
			}
			catch (DatabaseException &)
			{
				mysql_close(_db);
				throw;
			}
		}

		if (!db._autocommit)
		{
			try
			{
				autoCommit(_autocommit);
			}
			catch (DatabaseException* e)
			{
				mysql_close(_db);
				throw;
			}
		}
	}

	Database::~Database()
	{
		mysql_close(_db);
	}

	void Database::connect()
	{
		if (_host == "")
		{
			if (mysql_real_connect(_db, NULL, NULL, NULL, _database.c_str(), 0, NULL, 0) == NULL)
				throw DatabaseException(_db, "Error in Database::Connect");
		}
		else
		{
			if (mysql_real_connect(_db, _host.c_str(), _user.c_str(), _password.c_str(), _database.c_str(), _port, _unixSocket, _clientFlag) == NULL)
				throw DatabaseException(_db, "Error in Database::Connect");
		}

		_isConnected = true;

		if (mysql_set_character_set(_db, "utf8") != 0)
		{
			throw DatabaseException(_db, "Error in Database::Connect");
		}
	}


	void Database::setInitialCommand(const std::string &initialCommand)
	{
		_initialCommand = initialCommand;
	}

	bool Database::autoCommit() const
	{
		return _autocommit;
	}

	void Database::autoCommit(bool value)
	{
		int ac = (value) ? 1 : 0;
		if (mysql_autocommit(_db, ac) != 0)
			throw DatabaseException(_db, "Error in Database::Autocommit");
	}

	void Database::startTransaction()
	{
		if (mysql_query(_db, "START TRANSACTION") != 0)
			throw DatabaseException(_db, "Error in Dadabase::StartTransaction");
	}

	void Database::commit()
	{
		if (mysql_query(_db, "COMMIT") != 0)
			throw DatabaseException(_db, "Error in Database::Commit");
	}

	void Database::rollback()
	{
		if (mysql_query(_db, "ROLLBACK") != 0)
			throw DatabaseException(_db, "Error in Database::Rollback");
	}

	bool Database::isConnected()
	{
		return _isConnected;
	}

	void Database::useDatabase(const std::string &dbName)
	{
		if (mysql_select_db(_db, dbName.c_str()) != 0)
			throw DatabaseException(_db, "Error in Database::UseDatabase");
	}

	int Database::execute(const std::string &statement)
	{
		if (mysql_query(_db, statement.c_str()) != 0)
			throw DatabaseException(_db, "Error in Database::Execute");

		MYSQL_RES *result = mysql_store_result(_db);
		if (result != NULL)
		{
			mysql_free_result(result);
			throw DatabaseException("Error in Database::Execute", 0, "-----", "statements passed to execute should never return results.");
		}

		return mysql_affected_rows(_db);
	}

	void Database::libraryInitialize(bool embedded)
	{
		_embedded = embedded;

		if (!embedded)
		{
			if (mysql_library_init(0, NULL, NULL) != 0)
				throw DatabaseException("Error in Database::LibraryInitialize", 0, "-----", "Failure to initialize the database library");
		}
		else
		{
			static const char *server_args[] = { "this_program", "--basedir=/usr/local/mysql", "--datadir=/Users/ravidesai/mysql/data",
				"--plugin-dir=/Users/ravidesai/mysql/plugins", "--log-error=/Users/ravidesai/mysql/tmp/test.err",
				"--pid-file=/Users/ravidesai/mysql/tmp/test.pid",
				"--key_buffer_size=32M", "--log-bin=/Users/ravidesai/mysql/log/logbin"
				"--log-bin-trust-function-creators=1"
				"--log-bin-trust-routine-creators=1"
			};
			static const char *server_groups[] = { "embedded", "server", "this_program_SERVER", (char *)NULL };

			if (mysql_library_init(sizeof(server_args) / sizeof(char *), (char**)server_args, (char **)server_groups) != 0) {
				throw DatabaseException("Error in Database::Initialize", 0, "----", "Failure to initialize the database library");
			}
		}
	}

	void Database::threadInitialize()
	{
		if (mysql_thread_init() != 0)
			throw DatabaseException("Error in Database::ThreadInitialize", 0, "-----", "Failure to initialize database thread");
	}

	void Database::libraryFinalize()
	{
		mysql_library_end();
	}

	void Database::threadFinalize()
	{
		mysql_thread_end();
	}
	
	/************************************************************************/
	/* string::trim                                                                     */
	/************************************************************************/
	static inline std::string &ltrim(std::string &str)
	{
		str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::not1(std::ptr_fun<int, int>(std::isspace) )));
		return str;
	}

	static inline std::string &rtrim(std::string &str)
	{
		str.erase(std::find_if(str.rbegin(), str.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), str.end());
		return str;
	}

	static inline std::string &trim(std::string &str)
	{
		return ltrim(rtrim(str));
	}
	
	void Database::source(const std::string &fileName)
	{
		std::ifstream commands(fileName.c_str(), std::ios::in);
		if (!commands.is_open())
			throw DatabaseException("Error in Database::Source", 0, "-----", (std::string("could not open file: ") + fileName ).c_str());

		commands.exceptions(std::ios::badbit);

		try
		{
			std::string cmd;
			std::string collector;
			std::string delimiter;
			size_t delimpos;
			bool insideProcOrFunc = false;

			while (!commands.eof() )
			{
				getline(commands, cmd);
				cmd = trim(cmd);

				/** 跳过mysql的注释语句 */
				size_t dashDashPos = cmd.find("--");
				if(dashDashPos != std::string::npos && dashDashPos == 0)
					continue;

				/** 查找数据库名称 */
				delimpos = cmd.find("USE DATABASE ");
				if (delimpos != std::string::npos && delimpos == 0)
				{
					cmd.erase(0, 13);
					cmd = trim(cmd);
					useDatabase(cmd);
					continue;
				}

				/** 查找触发器 */
				delimpos = cmd.find("DELIMITER ");
				if (delimpos != std::string::npos && delimpos == 0)
				{
					delimiter = cmd.erase(0, 10);
					delimiter = trim(delimiter);
					continue;
				}

				/** 查找存储过程 */
				delimpos = cmd.find("CREATE PROC ");
				if (delimpos != std::string::npos && delimpos == 0)
				{
					insideProcOrFunc = true;
				}

				delimpos = cmd.find("CREATE FUNC ");
				if (delimpos != std::string::npos && delimpos == 0)
				{
					insideProcOrFunc = true;
				}

				if (insideProcOrFunc)
				{
					size_t poundPos = cmd.find("#");
					if (poundPos != std::string::npos)
					{
						/** remove pound(#) comment */
						cmd = cmd.erase(poundPos, cmd.length() - poundPos + 1);
					}
				}

				collector.append(" ");
				collector.append(cmd);

				delimpos = collector.rfind(delimiter.c_str());
				if (delimpos != std::string::npos && delimpos + delimiter.length() >= collector.length())
				{
					collector.replace(delimpos, delimiter.length(), "");

					if (insideProcOrFunc)
					{
						size_t commentStart = collector.find("/*");
						while (commentStart != std::string::npos )
						{
							size_t commentEnd = collector.find("*/");
							if (commentEnd == std::string::npos || commentEnd <= commentStart)
							{
								throw DatabaseException("Error in Database::Source", 0, "-----", "unmatched comment strings");
							}

							collector = collector.replace(commentStart, commentEnd - commentStart + 2, "");
							commentStart = collector.find("/*");
						}
					}

					execute(collector);
					collector = "";
					insideProcOrFunc = false;
				}

			}
		}
		catch (std::ifstream::failure &ex)
		{
			throw DatabaseException("Error while reading file in Database::Source", 0, "----", ex.what());
		}
	}


	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	LibraryInitializer::LibraryInitializer(bool embedded)
	{
		Database::libraryInitialize(embedded);
	}

	LibraryInitializer::~LibraryInitializer()
	{
		Database::libraryFinalize();
	}

	ThreadInitializer::ThreadInitializer()
	{
		Database::threadInitialize();
	}

	ThreadInitializer::~ThreadInitializer()
	{
		Database::threadFinalize();
	}

}
