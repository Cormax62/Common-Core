#include "PmergeMe.hpp"

std::vector<int> sortVector(std::vector<int> vet)
{
	std::vector<int>	seq;
	std::vector<int>	small;
	std::vector<int>	large;

	if (vet.size() == 1)
		return vet;
	else if (vet.size() == 2)
	{
		if (vet[0] < vet[1])
			return vet;
		else
		{
			std::vector<int> n;
			n.push_back(vet.back());
			n.push_back(vet.front());
			return n;
		}
	}
	for (std::vector<int>::iterator it = vet.begin(); it != vet.end(); it += 2)
	{
		int	n1 = *it;
		int	n2;

		if (it + 1 != vet.end())
			n2 = *(it + 1);
		else
		{
			small.push_back(n1);
			break;
		}
		if (n1 < n2)
		{
			small.push_back(n1);
			large.push_back(n2);
		}
		else
		{
			small.push_back(n2);
			large.push_back(n1);
		}
	}
	large = sortVector(large);
	if (small.size() > 2)
		seq = getSeq(small);
	else
		seq.push_back(1);
// dividere in un'altra funzione "return (fillVector(large, small, seq));"
	for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); it++)
	{
		std::vector<int>::iterator jt;
		if (large.size() == 1)
			jt = large.begin();
		else
			jt = large.begin() + (large.size() / 2) - 1;
		if (small[*it - 1] <= *jt)
		{
			while (jt >= large.begin())
			{
				if (*jt < small[*it - 1])
				{
					large.insert(jt, small[*it - 1]);
					break;
				}
				if (jt == large.begin())
				{
					large.insert(large.begin(), small[*it - 1]);
					break;
				}
				jt--;
			}
		}
		else if (small[*it - 1] > *jt)
		{
			while (jt != large.end())
			{
				if (*jt > small[*it - 1])
				{
					large.insert(jt, small[*it - 1]);
					break;
				}
				jt++;
			}
			if (jt == large.end())
				large.insert(jt, small[*it - 1]);
		}
	}
	std::vector<int>::iterator tt = seq.begin();
	for (std::vector<int>::iterator it = small.begin(); it != small.end(); it++)
	{
		std::vector<int>::iterator jt;
		if (large.size() == 1)
			jt = large.begin();
		else
			jt = large.begin() + (large.size() / 2) - 1;
		if (small[*tt - 1] == *it)
			tt++;
		else if (*it <= *jt)
		{
			while (jt >= large.begin())
			{
				if (*jt < *it)
				{
					large.insert(jt, *it);
					break;
				}
				else if (jt == large.begin())
				{
					large.insert(large.begin(), *it);
					break;
				}
				jt--;
			}
		}
		else if (*it > *jt)
		{
			while (jt != large.end())
			{
				if (*jt > *it)
				{
					large.insert(jt, *it);
					break;
				}
				jt++;
			}
			if (jt == large.end())
				large.insert(large.end(), *it);
		}
	}
	return large;
}

bool isValid(char** mtrx)
{
	int i;
	int j;

	for (j = 0; mtrx[j]; j++)
	{
		for (i = 0; mtrx[j][i]; i++)
		{
			if (isdigit(mtrx[j][i]) == false && mtrx[j][i] != ' ')
				return false;
		}
	}
	return true;
}

int main(int ac, char** av)
{
	if (ac == 1)
	{
		std::cout<<"Wrong arguments number."<<std::endl;
		return 0;
	}
	if (isValid(&av[1]) == false)
	{
		std::cout<<"Non-valid argument."<<std::endl;
	}
	std::vector<int> vet = createVector(&av[1]);
	vet = sortVector(vet);
	for (std::vector<int>::iterator it = vet.begin(); it != vet.end(); it++)
	{
		std::cout<<*it<<std::endl;
	}
	return 0;
}