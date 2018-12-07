#ifndef BINARY_H
#define BINARY_H

#include <MySQLLib/Export.h>
#include <string>

namespace MYSQLDB
{
	/**
	 * 二进制数据结构
	 */
	class MYSQLLIB_API Binary
	{
	public:
		Binary();
		Binary(size_t bufferSize);
		Binary(unsigned char *buffer, size_t bufferLength, size_t bufferSize);
		Binary(Binary &copy);

		virtual~Binary();
		Binary &operator=(const Binary &equal);

		void resizeBuffer(size_t newSize);
		void assignDataToBuffer(unsigned char *data, size_t dataLength);
		void subsumeBuffer(unsigned char *data, size_t dataLength, size_t bufferLength);
		void subsumeBuffer(Binary &binary);
		void clearBuffer();

		unsigned char *buffer() const;
		size_t bufferLength() const;
		size_t bufferSize() const;

	private:
		unsigned char *_buffer;
		size_t _bufferLength;
		size_t _bufferSize;
	};

	/** 等号比较符重载，用于比较两个二进制数据类的值是否一致 */
	bool operator==(const Binary &left, const Binary &right);
}

#endif // !BINARY_H
