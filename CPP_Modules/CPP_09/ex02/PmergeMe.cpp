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
	std::vector<int>	vet2;
	std::vector<int>	temp;
	int					n;

	if (static_cast<int>(vet.size()) < 3)
		return vet;
	for (int i = 2; i <= static_cast<int>(vet.size()); i++)
	{
		n = (pow(2, i) - (pow(-1, i))) / 3;
		if (n > 0 && n < static_cast<int>(vet.size()))
			seq.push_back(n);
	}
	for (int i = 0; i < static_cast<int>(vet.size()); i++)
	{
		if (std::find(seq.begin(), seq.end(), i + 1) == vet.end())
			temp.push_back(vet[i]);
		else
			vet2.push_back(vet[i]);
	}
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		vet2.push_back(*it);
	}
	return vet2;
}
