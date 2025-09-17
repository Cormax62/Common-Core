#include "Includes.hpp"

// ------------- BASE -------------

Base::~Base(){}

// ------------- FUNCTIONS -------------

Base* generate()
{
	int n;
	Base* p;

	srand((unsigned)time(NULL));
	n = rand();
	if ((n % 3) == 0)
		p = new A;
	if ((n % 3) == 1)
		p = new B;
	if ((n % 3) == 2)
		p = new C;
	return(p);
}

void identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout<<"identifier1, type: A"<<std::endl;
	if (b)
		std::cout<<"identifier1, type: B"<<std::endl;
	if (c)
		std::cout<<"identifier1, type: C"<<std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout<<"identifier2, type: A"<<std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout<<"identifier2, type: B"<<std::endl;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout<<"identifier2, type: C"<<std::endl;
	}
	catch(const std::exception& e)
	{}
	
}
