#ifndef PARAMBUFFER_H
#define PARAMBUFFER_H

#include <MySQLLib/Export.h>
#include <mysql.h>

#include <string>
#include <typeinfo>

#include <MySQLLib/Binary.h>

namespace MYSQLDB
{
	/**
	 * 与mysql数据库数据类型相关类
	 */
	class MYSQLLIB_API ParamBuffer
	{
	public:
		ParamBuffer(const enum_field_types type, bool isUnsigned);
		ParamBuffer(const std::type_info &info);
		ParamBuffer(const std::string &str, size_t maxSize);
		ParamBuffer(const std::string &str);
		ParamBuffer(const short int i);
		ParamBuffer(const unsigned short int i);
		ParamBuffer(const int i);
		ParamBuffer(const unsigned int i);
		ParamBuffer(const Binary &data);
		ParamBuffer(const char ch);
		ParamBuffer(const unsigned char ch);
		ParamBuffer(const float f);
		ParamBuffer(const double d);

		ParamBuffer(const ParamBuffer &copy);
		~ParamBuffer();

		void resizeBlob(size_t newSize);

		void *buffer() const;
		enum_field_types bufferType() const;
		size_t bufferSize() const;
		unsigned long *bufferLength();

		bool isNull();
		bool isUnsigned();
		bool isTruncated();
		bool error();

	private:
		void *_buffer;
		size_t _bufferSize;
		unsigned long _bufferLength;
		enum_field_types _type;
		bool _isNull;
		bool _isUnsigned;
		bool _isTruncated;
		bool _error;

	};
}

#endif // !PARAMBUFFER_H
