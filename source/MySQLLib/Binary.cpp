#include <MySQLLib/Binary.h>

namespace MYSQLDB
{
	Binary::Binary()
	{
		_bufferLength = 0;
		_bufferSize = 0;
		_buffer = nullptr;
	}

	Binary::Binary(size_t bufferSize)
	{
		_bufferLength = 0;
		_bufferSize = bufferSize;
		_buffer = nullptr;

		if (_bufferSize > 0)
			_buffer = new unsigned char [bufferSize];

	}

	Binary::Binary(unsigned char *buffer, size_t bufferLength, size_t bufferSize)
	{
		_bufferSize = bufferSize;
		if (bufferLength > _bufferSize)
			_bufferSize = bufferLength;
		
		_bufferLength = bufferLength;
		_buffer = buffer;
	}

	Binary::Binary(Binary &copy)
	{
		_bufferLength = 0;
		_bufferSize = 0;
		_buffer = nullptr;

		subsumeBuffer(copy);
	}

	Binary &Binary::operator=(const Binary &equal)
	{
		if (_bufferSize < equal._bufferSize)
		{
			if (_buffer != nullptr)
				delete[] _buffer;

			_bufferSize = equal._bufferSize;
			_buffer = new unsigned char[_bufferSize];
		}

		_bufferLength = equal._bufferLength;
		if (_bufferLength > 0)
			memcpy(_buffer, equal._buffer, _bufferLength);

		return *this;
	}

	Binary::~Binary()
	{
		clearBuffer();
	}

	void Binary::clearBuffer()
	{
		if (_buffer != nullptr)
		{
			delete _buffer;
			_buffer = nullptr;
		}
		_bufferSize = 0;
		_bufferLength = 0;
	}

	size_t Binary::bufferLength() const
	{
		return _bufferLength;
	}

	size_t Binary::bufferSize() const
	{
		return _bufferSize;
	}

	unsigned char * Binary::buffer() const
	{
		return _buffer;
	}


	void Binary::resizeBuffer(size_t newSize)
	{
		if (_bufferLength > newSize)
			return;

		unsigned char *newBuffer = new unsigned char[newSize];
		if (_buffer != nullptr)
		{
			if (_bufferLength > 0)
			{
				memcpy(newBuffer, _buffer, _bufferLength);
			}
			delete _buffer;

		}
		_bufferSize = newSize;
		_buffer = newBuffer;
	}

	void Binary::assignDataToBuffer(unsigned char *data, size_t dataLength)
	{
		if (_bufferLength < dataLength)
		{
			_bufferLength = 0;
			resizeBuffer(dataLength);
		}
		_bufferLength = dataLength;
		memcpy(_buffer, data, dataLength);
	}


	void Binary::subsumeBuffer(unsigned char *data, size_t dataLength, size_t bufferLength)
	{
		if (_buffer)
			delete _buffer;
		_bufferSize = dataLength;
		_bufferLength = bufferLength;
		_buffer = data;
	}

	void Binary::subsumeBuffer(Binary &binary)
	{
		if (_buffer)
			delete _buffer;

		_bufferSize = binary._bufferSize;
		_bufferLength = binary._bufferLength;
		_buffer = binary._buffer;
	}

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	bool operator==(const Binary &left, const Binary &right)
	{
		unsigned char *leftBuffer = left.buffer();
		unsigned char *rightBuffer = right.buffer();

		size_t leftLen = left.bufferLength();
		size_t rigthLen = right.bufferLength();

		if (leftLen != rigthLen) return false;

		for (size_t i = 0; i < leftLen; i++)
		{
			if (leftBuffer[i] != rightBuffer[i]) return false;
		}
		return true;
	}
}