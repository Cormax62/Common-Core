#include "PmergeMe.hpp"

std::vector<int> sortVector(std::vector<int> vet)
{
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
	small = getSeq(small);
    for (size_t i = 0; i < small.size(); ++i)
    {
		size_t	left = 0;
		size_t	right = large.size();
        int		value = small[i];

        if (large.empty())
        {
            large.push_back(value);
            continue;
        }
        while (left < right)
		{
			size_t	mid = left + (right - left) / 2;

			if (large[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		large.insert(large.begin() + left, value);
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