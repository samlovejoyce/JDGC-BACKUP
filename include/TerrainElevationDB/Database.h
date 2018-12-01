#ifndef DBENGINE_H
#define DBENGINE_H

#include <TerrainElevationDB/Export.h>

#include <mysql.h>

namespace TerrainElevation {

	class TERRAINELEVATIONDB_PAI Database
	{
	public:
		~Database();

		/** �������ݿ�ʵ��ָ�� */
		static Database* getInstance();

		/** ���ӵ����ݿ�����Ƿ�ɹ� */
		bool connectDB();

		/** ���ݿ��ѯ */
		MYSQL_RES *queryDB(MYSQL *mysql, const char *query);

		/** �ر����ݿ����Ӽ����� */
		void closeDB();

		/** ����MYSQLʵ��ָ�� */
		MYSQL* getDB() { return db; }

	private:
		static Database* instance;
		Database();

		MYSQL *db;
	};
}
#endif // !DBENGINE_H
