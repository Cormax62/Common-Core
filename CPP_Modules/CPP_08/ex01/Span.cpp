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
	if (static_cast<unsigned int>(v.size()) == limit)
		throw LimitReached();
	v.push_back(num);
}

void Span::randomFill()
{
	int n;

	srand((unsigned)time(NULL));
	for (unsigned int i = 0; i < limit; i++)
	{
		n = rand();
		v.push_back(n);
	}
}

int		Span::shortestSpan()
{
	int	temp = *std::max_element(v.begin(), v.end());

	if (v.size() == 0 || v.size() == 1)
	{
		throw NotEnoughMember();
	}
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		for (std::vector<int>::iterator j = v.begin(); j != v.end(); j++)
		{
			if (*i != *j)
			{
				if (abs(*i - *j) < temp)
					temp = abs(*i - *j);
			}
		}
	}
	return (temp);
}

int		Span::longestSpan()
{
	std::vector<int>::iterator max = std::max_element(v.begin(), v.end());
	std::vector<int>::iterator min = std::min_element(v.begin(), v.end());

	return (*max - *min);
}
