#include "RPN.hpp"

int main(int ac, char** av)
{
	std::stack<int>	stack;
	int				n1;
	int				n2;

	if (ac != 2)
		return (std::cout<<"You need to pass a string for this excerise"<<std::endl, 0);
	for (int i = 0; av[1][i]; i++)
	{
		if (isdigit(av[1][i]))
		{
			stack.push(static_cast<int>(av[1][i] - 48));
			continue;
		}
		switch (av[1][i])
        {
		case '+':
			if (stack.size() < 2)
				return (std::cout<<"Wrong format"<<std::endl, 0);
			n2 = stack.top(); 
			stack.pop();
			n1 = stack.top(); 
			stack.pop();
			stack.push(n1 + n2);
			break;
		case '-':
			if (stack.size() < 2)
				return (std::cout<<"Wrong format"<<std::endl, 0);
			n2 = stack.top(); 
			stack.pop();
			n1 = stack.top(); 
			stack.pop();
			stack.push(n1 - n2);
			break;
		case '*':
			if (stack.size() < 2)
				return (std::cout<<"Wrong format"<<std::endl, 0);
			n2 = stack.top(); 
			stack.pop();
			n1 = stack.top(); 
			stack.pop();
			stack.push(n1 * n2);
			break;
		case '/':
			if (stack.size() < 2)
				return (std::cout<<"Wrong format"<<std::endl, 0);
			n2 = stack.top(); 
			stack.pop();
			n1 = stack.top(); 
			stack.pop();
			if (n2 == 0)
				return (std::cout<<"Divide by 0"<<std::endl, 0);
			stack.push(n1 / n2);
			break;
		case ' ':
			break;
		default:
			return (std::cout<<"Wrong format"<<std::endl, 0);
		}
	}
	if (stack.size() > 1)
		return (std::cout<<"There are still some number in the stack btw"<<std::endl, 0);
	std::cout<<stack.top()<<std::endl;
	return 0;
}