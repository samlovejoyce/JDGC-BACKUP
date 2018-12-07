#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <MySQLLib/Export.h>

#include <iostream>
#include <mysql.h>

namespace MYSQLDB
{
	/**
	 * 数据库异常信息显示类
	 */
	class MYSQLLIB_API DatabaseException
	{
	public:
		DatabaseException(const std::string &initialMessage, const int errorno, const char *sqlState, const char *errorMessage);
		DatabaseException(MYSQL *db, const std::string &initialMessage);
		DatabaseException(MYSQL_STMT *stmt, const std::string &initialMessage);

		/** friend function is not a member function of any class */
		friend std::ostream &operator<<(std::ostream &out, const DatabaseException &exp);

	private:
		int _errorno;
		std::string _sqlState;
		std::string _initialMessage;
		std::string _errorMessage;
	};
}

#endif // !DATABASEEXCEPTION_H
