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
		_buffer = new void *[sizeof(unsigned short int)];
		_bufferSize = sizeof(unsigned short int);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_SHORT;
		_isNull = false;
		_isUnsigned = true;
		_isTruncated = false;

		*((unsigned short int *)_buffer) = i;
	}
	
	ParamBuffer::ParamBuffer(const int i)
	{
		_buffer = new void *[sizeof( int)];
		_bufferSize = sizeof( int);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_LONG;
		_isNull = false;
		_isUnsigned = false;
		_isTruncated = false;

		*((int *)_buffer) = i;
	}
	
	ParamBuffer::ParamBuffer(const unsigned int i)
	{
		_buffer = new void *[sizeof(unsigned int)];
		_bufferSize = sizeof(unsigned int);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_LONG;
		_isNull = false;
		_isUnsigned = true;
		_isTruncated = false;

		*((unsigned int *)_buffer) = i;
	}
	
	ParamBuffer::ParamBuffer(const Binary &data)
	{
		_buffer = new void *[sizeof(Binary)];
		_bufferSize = data.bufferSize();
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_BLOB;
		_isNull = false;
		_isUnsigned = false;
		_isTruncated = false;

		memcpy(_buffer, data.buffer(), sizeof(Binary));
	}
	
	ParamBuffer::ParamBuffer(const char ch)
	{
		_bufferSize = sizeof(char);
		_buffer = new void* [sizeof(_bufferSize)];
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_TINY;
		_isNull = false;
		_isTruncated = false;
		_isUnsigned = false;

		*((char *)_buffer) = ch;
	}
	
	ParamBuffer::ParamBuffer(const unsigned char ch)
	{
		_bufferSize = sizeof(char);
		_buffer = new void*[sizeof(_bufferSize)];
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_TINY;
		_isNull = false;
		_isTruncated = false;
		_isUnsigned = false;

		*((char *)_buffer) = ch;
	}
	
	ParamBuffer::ParamBuffer(const float f)
	{
		_buffer = new void*[(sizeof(float))];
		_bufferSize = sizeof(float);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_FLOAT;
		_isNull = false;
		_isTruncated = false;
		_isUnsigned = true;

		*((float *)_buffer) = f;
	}
	
	ParamBuffer::ParamBuffer(const double d)
	{
		_buffer = new void*[(sizeof(double))];
		_bufferSize = sizeof(double);
		_bufferLength = _bufferSize;
		_type = MYSQL_TYPE_DOUBLE;
		_isNull = false;
		_isTruncated = false;
		_isUnsigned = true;

		*((double *)_buffer) = d;
	}

	ParamBuffer::ParamBuffer(const ParamBuffer &copy)
	{
		
	}

	ParamBuffer::~ParamBuffer()
	{
		if (_buffer)
		{
			delete _buffer;
			_buffer = nullptr;
		}
		_bufferSize = 0;
		_bufferLength = 0;
		_isNull = true;
	}

	void ParamBuffer::resizeBlob(size_t newSize)
	{
		if (_type != MYSQL_TYPE_BLOB) 
		{
			throw DatabaseException("Error in ParamBuffer::ResizeBlob", 0, "----", "Datatype is not blob");
		}

		if (_bufferSize != newSize) 
		{
			free(_buffer);
			_buffer = new void* [newSize];
			_bufferSize = newSize;
			_bufferLength = 0;
		}
	}

	void *ParamBuffer::buffer() const
	{
		return _buffer;
	}

	enum_field_types ParamBuffer::bufferType() const
	{
		return _type;
	}

	size_t ParamBuffer::bufferSize() const
	{
		return _bufferSize;
	}

	unsigned long *ParamBuffer::bufferLength()
	{
		return &_bufferLength;
	}

	bool ParamBuffer::isNull()
	{
		return _isNull;
	}
	bool ParamBuffer::isUnsigned()
	{
		return _isUnsigned;
	}
	bool ParamBuffer::isTruncated()
	{
		return _isTruncated;
	}
	bool ParamBuffer::error()
	{
		return _errno;
	}
}