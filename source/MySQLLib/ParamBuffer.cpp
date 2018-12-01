#include <MySQLLib/ParamBuffer.h>
#include <MySQLLib/DatabaseException.h>

namespace MYSQLDB
{
	ParamBuffer::ParamBuffer(const enum_field_types type, bool isUnsigned)
	{
		_type = type;
		_buffer = nullptr;
		_bufferSize = 0;
		_bufferLength = 0;
		_isNull = true;
		_isUnsigned = isUnsigned;
	}

	ParamBuffer::ParamBuffer(const std::type_info &info)
	{
		bool isUnsigned = false;

		if (info == typeid(std::string))
		{
			_type = MYSQL_TYPE_STRING;
		}
		else if (info == typeid(Binary))
		{
			_type = MYSQL_TYPE_BLOB;
		}
		else if (info == typeid(double))
		{
			_type = MYSQL_TYPE_DOUBLE;
		}
		else if( info == typeid(float) )
		{
			_type = MYSQL_TYPE_FLOAT;
		}
		else if (info == typeid(char))
		{
			_type = MYSQL_TYPE_TINY;
		}
		else if (info == typeid(unsigned char))
		{
			_type = MYSQL_TYPE_TINY;
			isUnsigned = true;
		}
		else if (info == typeid(short) )
		{
			_type = MYSQL_TYPE_SHORT;
		}
		else if (info == typeid(unsigned short))
		{
			_type = MYSQL_TYPE_SHORT;
			isUnsigned = true;
		}
		else if (info == typeid(int) )
		{
			_type = MYSQL_TYPE_LONG;
		}
		else if (info == typeid(unsigned int))
		{
			_type = MYSQL_TYPE_LONG;
			isUnsigned = true;
		}

		_buffer = nullptr;
		_bufferSize = 0;
		_bufferLength = 0;
		_isNull = true;
		_isUnsigned = isUnsigned;

	}

	ParamBuffer::ParamBuffer(const std::string &str, size_t maxSize)
	{
		if (str.size() > maxSize)
			throw DatabaseException("Error in ParamBuffer::ParamBuffer(std::string)", 0, "-----", "length of str parameter is greater  than maxSize");

		if (maxSize > 0)
		{
			_buffer = new void *[maxSize];
			_bufferSize = maxSize;
			_bufferLength = str.length();
			_type = MYSQL_TYPE_STRING;
			_isNull = false;
		}
		else
		{
			_buffer = nullptr;
			_bufferSize = 0;
			_bufferLength = 0;
			_type = MYSQL_TYPE_STRING;
			_isNull = true;
		}
		memcpy(_buffer, str.data(), str.length());
	}

	ParamBuffer::ParamBuffer(const std::string &str)
		:ParamBuffer(str, str.length())
	{

	}
	
	ParamBuffer::ParamBuffer(const short int i)
	{
		_buffer = new void *[sizeof(short int)];
		_bufferSize = sizeof(short int);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_SHORT;
		_isNull = false;
		_isUnsigned = false;
		_isTruncated = false;

		*((unsigned int *)_buffer) = i;
	}
	
	ParamBuffer::ParamBuffer(const unsigned short int i)
	{
		_buffer = new void *[sizeof(short int)];
		_bufferSize = sizeof(short int);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_SHORT;
		_isNull = false;
		_isUnsigned = true;
		_isTruncated = false;

		*((unsigned int *)_buffer) = i;
	}
	
	ParamBuffer::ParamBuffer(const int i)
	{

	}
	
	ParamBuffer::ParamBuffer(const unsigned int i)
	{

	}
	
	ParamBuffer::ParamBuffer(const Binary &data)
	{

	}
	
	ParamBuffer::ParamBuffer(const char ch)
	{

	}
	
	ParamBuffer::ParamBuffer(const unsigned char ch)
	{

	}
	
	ParamBuffer::ParamBuffer(const float f)
	{

	}
	
	ParamBuffer::ParamBuffer(const double d)
	{

	}
}