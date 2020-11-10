#pragma once
#include <exception>

#include "pch.h"

class Error: public _exception
{
protected:
	int number;
	const char* error;
	int level;

public:
	Error(int _number, const char* _error, int _level) throw();
	virtual const char* What() const throw();
	int GetLevel() const throw();
	~Error();

private:

};