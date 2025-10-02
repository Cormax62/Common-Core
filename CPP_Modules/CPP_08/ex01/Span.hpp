#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>

class Span
{
private:
	std::vector<int>	v;
	unsigned int		limit;
public:
	Span(unsigned int n);
	Span(const Span& other);
	~Span();

	const Span& operator=(const Span& other);

	void	addNumber(int num);
	void	randomFill();
	int		shortestSpan();
	int		longestSpan();

	class LimitReached : public std::exception
	{
	public:
		const char *what() const throw() {
			return("limit reached");
	}
	};

	class NotEnoughMember : public std::exception
	{
	public:
		const char *what() const throw() {
			return("not enough numbers");
	}
	};
};

#endif