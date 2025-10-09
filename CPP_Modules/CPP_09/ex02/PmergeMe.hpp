#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>

class PmergeMe
{
public:
	std::vector<int>	smallest;
	std::list<int>		greatest;

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	~PmergeMe();

	const PmergeMe& operator=(const PmergeMe& other);
};

#endif