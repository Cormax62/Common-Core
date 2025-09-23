#include "Array.hpp"

int main()
{
	{
		Array<int> array(4);

		try
		{
			for (int i = 0; i < 4; ++i)
			{
				array[i] = i + 1;
			}
			for (int i = 0; i < 4; ++i)
			{
				std::cout<<array[i]<<std::endl;
			}
		}
		catch (std::exception &e) {}
	}
	{
		Array<char> array1(7);
		Array<char> array2(7);

		try
		{
			for (int i = 0; i < 7; ++i)
			{
				array1[i] = i + 82;
			}
			for (int i = 0; i < 7; ++i)
			{
				std::cout<<array1[i]<<std::endl;
			}
			array2 = array1;
			for (int i = 0; i < 7; ++i)
			{
				array1[i] -= 10;
			}
			for (int i = 0; i < 7; ++i)
			{
				std::cout<<array1[i];
				std::cout<<array2[i]<<std::endl;
			}
		}
		catch (std::exception &e) {}
	}
}