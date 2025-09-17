#include "Includes.hpp"

int main()
{
	Base* p;

	p = generate();
	identify(p);
	identify(*p);
	return(0);
}