#include "Move.h"
#include <iostream>

Move::Move(int d)
{
	std::cout << "Constructor called for " << d << std::endl;
	data = new int;
	*data = d;
}

Move::Move(const Move& source):Move(*source.data)
{
	std::cout << "Copy constructor called for " << *source.data << std::endl;
}

Move::Move(Move&& source):data{source.data}
{
	std::cout << "Move constructor called for " << *source.data << std::endl;
	source.data = nullptr;
}

Move::~Move()
{
	if (data) 
	{
		std::cout << "Destructor called for " << *data << std::endl;
	}
	else
	{
		std::cout << "Destructor called for nullptr"<< std::endl;

	}
	delete data;
}
