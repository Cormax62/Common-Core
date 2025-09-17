#ifndef INCLUDES_HPP
# define INCLUDES_HPP

# include <iostream>
# include  <cstdlib>

class Base
{
private:
	
public:
	virtual ~Base();
};

class A : public Base
{};
class B : public Base
{};
class C : public Base
{};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif