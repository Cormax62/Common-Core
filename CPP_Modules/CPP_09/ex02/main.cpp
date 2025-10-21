#include "PmergeMe.hpp"

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
	struct timeval	start;
	struct timeval	end;
	double			time;

	if (ac == 1)
	{
		std::cout<<"Wrong arguments number."<<std::endl;
		return 0;
	}
	if (isValid(&av[1]) == false)
	{
		std::cout<<"Non-valid argument."<<std::endl;
	}
	std::vector<int> vet1 = createVector<std::vector<int> >(&av[1]);
	std::cout<<"Before: ";
	for (std::vector<int>::iterator it = vet1.begin(); it != vet1.end(); it++)
	{
		std::cout<<" "<<*it;
	}
	std::cout<<std::endl;
	gettimeofday(&start, NULL);
	vet1 = sortVector(vet1);
	gettimeofday(&end, NULL);
	time = static_cast<double>((end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec)) / 1000000.0;
	std::cout<<"After: ";
	for (std::vector<int>::iterator it = vet1.begin(); it != vet1.end(); it++)
	{
		std::cout<<" "<<*it;
	}
	std::cout<<std::endl;
	std::cout<<"Time to process a range of "<<std::fixed<<std::setprecision(6)<<ac - 1<<" elements with std::vector : "<<time<<" μs"<<std::endl;
	std::deque<int> vet2 = createVector<std::deque<int> >(&av[1]);
	// std::cout<<"Before: ";
	// for (std::deque<int>::iterator it = vet2.begin(); it != vet2.end(); it++)
	// {
	// 	std::cout<<" "<<*it;
	// }
	gettimeofday(&start, NULL);
	vet2 = sortVector(vet2);
	gettimeofday(&end, NULL);
	time = static_cast<double>((end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec)) / 1000000.0;
	// std::cout<<"After: ";
	// for (std::deque<int>::iterator it = vet2.begin(); it != vet2.end(); it++)
	// {
	// 	std::cout<<" "<<*it;
	// }
	// std::cout<<std::endl;
	std::cout<<"Time to process a range of "<<std::fixed<<std::setprecision(6)<<ac - 1<<" elements with std::deque : "<<time<<" μs"<<std::endl;
	return 0;
}