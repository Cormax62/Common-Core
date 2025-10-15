#include "PmergeMe.hpp"

std::vector<int> createVector(char** mtrx)
{
	std::vector<int> vet;

	for (int i = 0; mtrx[i]; i++)
		vet.push_back(atoi(mtrx[i]));
	return vet;
}

std::vector<int> getSeq(std::vector<int> vet)
{
	std::vector<int>	seq;
	int					n;

	for (int i = 2; i <= static_cast<int>(vet.size()); i++)
	{
		n = (pow(2, i) - (pow(-1, i))) / 3;
		if (n > 0 && n < static_cast<int>(vet.size()))
			seq.push_back(n);
	}
	return seq;
}

// std::vector<int> sortVector(std::vector<int> vet)
// {
// 	std::vector<int>	seq;
// 	std::vector<int>	small;
// 	std::vector<int>	large;

// 	if (vet.size() == 1)
// 		return vet;
// 	else if (vet.size() == 2)
// 	{
// 		if (vet[0] < vet[1])
// 			return vet;
// 		else
// 		{
// 			std::vector<int> n;
// 			n.push_back(vet.back());
// 			n.push_back(vet.front());
// 			return n;
// 		}
// 	}
// 	for (std::vector<int>::iterator it = vet.begin(); it != vet.end(); it += 2)
// 	{
// 		int	n1 = *it;
// 		int	n2;

// 		if (it + 1 != vet.end())
// 			n2 = *(it + 1);
// 		else
// 		{
// 			small.push_back(n1);
// 			break;
// 		}
// 		if (n1 < n2)
// 		{
// 			small.push_back(n1);
// 			large.push_back(n2);
// 		}
// 		else
// 		{
// 			small.push_back(n2);
// 			large.push_back(n1);
// 		}
// 	}
// 	large = sortVector(large);
// 	if (small.size() > 2)
// 		seq = getSeq(small);
// 	else
// 		seq.push_back(1);
// // dividere in un'altra funzione "return (fillVector(large, small, seq));"
// 	for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
// 	{
// 		std::vector<int>::iterator jt = large.begin() + (large.size() / 2) - 1;
// 		if (small[*it] <= *jt)
// 		{
// 			while (jt >= large.begin())
// 			{
// 				if (*jt < small[*it])
// 				{
// 					large.insert(jt, small[*it]);
// 					break;
// 				}
// 				if (jt == large.begin())
// 				{
// 					large.insert(large.begin(), small[*it]);
// 					break;
// 				}
// 				jt--;
// 			}
// 		}
// 		else if (small[*it] > *jt)
// 		{
// 			while (jt != large.end())
// 			{
// 				if (*jt > small[*it])
// 				{
// 					large.insert(jt + 1, small[*it]);
// 					break;
// 				}
// 				jt++;
// 			}
// 			if (jt == large.end())
// 				large.insert(jt, *it);
// 		}
// 	}
// 	for (std::vector<int>::iterator it = small.begin(); it != small.end(); it++)
// 	{
// 		std::vector<int>::iterator jt = large.begin() + (large.size() / 2) - 1;
// 		std::vector<int>::iterator tt = seq.begin();
// 		if (small[*tt] == *it)
// 			tt++;
// 		else if (*it <= *jt)
// 		{
// 			while (jt >= large.begin())
// 			{
// 				if (*jt < *it)
// 				{
// 					large.insert(jt, *it);
// 					break;
// 				}
// 				else if (jt == large.begin())
// 				{
// 					large.insert(large.begin(), small[*it]);
// 					break;
// 				}
// 				jt--;
// 			}
// 		}
// 		else if (*it > *jt)
// 		{
// 			while (jt != large.end())
// 			{
// 				if (*jt > *it)
// 				{
// 					large.insert(jt + 1, *it);
// 					break;
// 				}
// 				jt++;
// 			}
// 			if (jt == large.end())
// 				large.insert(large.end(), *it);
// 		}
// 	}
// 	return large;
// }

// // -------------- CONSTUCTORS AND DESTRUCTOR --------------

// PmergeMeVector::PmergeMeVector(char** mtrx)
// {
// 	std::vector<int> temp;

// 	for (int i = 0; mtrx[i]; i++)
// 		temp.push_back(std::atoi(mtrx[i]));
// 	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it += 2)
// 	{
// 		int	n1 = *it;
// 		int	n2 = *(it + 1);

// 		if (n1 < n2)
// 		{
// 			small.push_back(n1);
// 			large.push_back(n2);
// 		}
// 		else
// 		{
// 			small.push_back(n2);
// 			large.push_back(n1);
// 		}
// 	}
// }

// PmergeMeVector::PmergeMeVector(const PmergeMeVector& other) {}

// PmergeMeVector::~PmergeMeVector() {}

// PmergeMeList::PmergeMeList(char** mtrx)
// {

// }

// PmergeMeList::PmergeMeList(const PmergeMeList& other) {}

// PmergeMeList::~PmergeMeList() {}

// // -------------- OPERATOR --------------

// const PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& other) {}

// const PmergeMeList& PmergeMeList::operator=(const PmergeMeList& other) {}

// // -------------- FUNCTIONS --------------
