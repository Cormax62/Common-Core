#include "Serializer.hpp"

int main()
{
	Data		*ptr1;
	Data		*ptr2;
	uintptr_t	num;

	ptr1 = new Data;
	ptr1->num = 19456;
	num = Serializer::serialize(ptr1);
	ptr2 = Serializer::deserialize(num);
	std::cout<<ptr1->num<<std::endl;
}