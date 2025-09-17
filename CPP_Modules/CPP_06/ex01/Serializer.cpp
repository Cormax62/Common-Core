#include "Serializer.hpp"

// ------------- CONSTRUCTORS AND DESTRUCTOR -------------

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer::~Serializer()
{
}

// ------------- OPERATOR -------------

const Serializer& Serializer::operator=(const Serializer& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

// ------------- FUNCTION -------------

uintptr_t	Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
