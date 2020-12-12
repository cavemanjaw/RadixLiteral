#ifndef LITERAL_BUFFER_HPP
#define LITERAL_BUFFER_HPP

#include "utils.hpp"
#include <cstring>
#include <string>


// TODO: Move to .c implementation file
class LiteralBuffer
{
public:
	// TODO: Argument for the buffer size?
	//constexpr
	LiteralBuffer()
		: size{std::size_t{0}}
	{
		std::memset(buffer, '\0', sizeof(buffer));
	}

	LiteralBuffer(const LiteralBuffer& rhs) = default;
	LiteralBuffer& operator=(const LiteralBuffer& rhs) = default;

	std::size_t Length()
	{
		return size;
	}


	void Insert(char charToAppend, std::size_t position)
	{
		buffer[position] = charToAppend;
		size++;
	}


	void Insert(char charToAppend)
	{
		buffer[size] = charToAppend;
		size++;
	}


	void Delete(std::size_t position)
	{
		buffer[position] = '\0';
		size--;
	}

	// TODO: Theoretically should be const to not leak the resources from LiteralBuffer objects,
	// but this would require many changes and will break many things
	char* GetBuffer()
	{
		return buffer;
	}

	operator std::string()
	{
		return std::string{GetBuffer()};
	}


private:
	// TODO: constexpr specifier for calculation of buffer array size
	char buffer[BufferSize()];
	std::size_t size;
};


#endif // #ifndef LITERAL_BUFFER_HPP
