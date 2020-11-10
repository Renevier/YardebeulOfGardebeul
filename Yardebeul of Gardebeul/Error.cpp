#include "Error.h"

Error::Error(int _number, const char* _error, int _level) throw()
{
	this->number = _number;
	this->error = _error;
	this->level = _level;
}

const char* Error::What() const throw()
{
	return this->error;
}

int Error::GetLevel() const throw()
{
	return this->level;
}

Error::~Error()
{
}
