#include "Span.hpp"

// ----------- CONSTRUCTOR AND DESCTRUCTOR -----------

Span::Span(unsigned int n)
{
	this->limit = n;
}

Span::Span(const Span& other)
{
	this->limit = other.limit;
	this->v = other.v;
}

Span::~Span()
{
}

// ----------- OPERATOR -----------

const Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	this->limit = other.limit;
	this->v = other.v;
	return *this;
}

// ----------- FUNCTIONS -----------

void Span::addNumber(int num)
{
	if (static_cast<int>(v.size()) == limit)
		throw LimitReached();
	v.push_back(num);
}

void Span::randomFill()
{
	int n;

	srand((unsigned)time(NULL));
	for (int i = 0; i < limit; i++)
	{
		n = rand();
		v.push_back(n);
	}
}

int		Span::shortestSpan()
{
	int	min;
	int	max;
	int	temp = 2147483647;
	int	temp2 = 0;

	for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		min = *i;
		max = 2147483647;
		for (std::vector<int>::iterator j = v.begin(); j != v.end(); j++)
		{
			if (min != *j)
			{
				if (abs(min - *j) < abs(min - max))
					max = *j;
			}
		}
		if (abs(temp - temp2) > abs(min - max))
		{
			temp = min;
			temp2 = max;
		}
	}
	return (abs(temp - temp2));
}

int		Span::longestSpan()
{
	std::vector<int>::iterator it;
	int	min = 2147483647;
	int	max = -2147483648;

	for (it = v.begin(); it != v.end(); it++)
	{
		if (min > *it)
			min = *it;
		if (max < *it)
			max = *it;
	}
	return (abs(max - min));
}
