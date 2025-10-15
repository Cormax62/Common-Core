#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <vector>
# include <cmath>

std::vector<int> createVector(char** mtrx);
std::vector<int> sortVector(std::vector<int> vet);
std::vector<int> getSeq(std::vector<int> vet);

// class PmergeMeVector
// {
// public:
// 	std::vector<int>	small;
// 	std::vector<int>	large;

// 	PmergeMeVector(char** mtrx);
// 	PmergeMeVector(const PmergeMeVector& other);
// 	~PmergeMeVector();

// 	const PmergeMeVector& operator=(const PmergeMeVector& other);
// };

// class PmergeMeList
// {
// public:
// 	std::list<int>	small;
// 	std::list<int>	large;

// 	PmergeMeList(char** mtrx);
// 	PmergeMeList(const PmergeMeList& other);
// 	~PmergeMeList();

// 	const PmergeMeList& operator=(const PmergeMeList& other);
// };

#endif