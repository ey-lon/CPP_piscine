#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand((unsigned int)time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		delete [] mirror;//
	}

	{
		int len = 100;
		Array<int> arr1(len);

		srand((unsigned int)time(NULL));
		for (int i = 0; i < len; i++)
		{
			const int value = (rand() % 100);
			arr1[i] = value;
		}

		Array<int> arr2 = arr1;
		Array<int> arr3(arr2);

		for (int i = 0; i < len; i++)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;
	}
    return 0;
}
