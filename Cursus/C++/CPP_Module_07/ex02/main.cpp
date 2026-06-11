#include "./src/class/Array.hpp"
#include <iostream>

int main()
{
	Array<char> arr(5);
	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = 'c';
	arr[3] = 'd';
	arr[4] = 'e';

	for (size_t i = 0; i < 5; i++)
		std::cout << arr[i] << '\n';
	std::cout << std::endl;

	Array<int> arr2(5);
	arr2[0] = 1;
	arr2[1] = 2;
	arr2[2] = 3;
	arr2[3] = 4;
	arr2[4] = 5;

	for (size_t i = 0; i < 5; i++)
		std::cout << arr2[i] << ' ';
	std::cout << std::endl;

	Array<int> arr3(5);
	std::cout << "Size of arr3: " << arr3.size() << std::endl;
	std::cout << "Contents of arr3: ";
	for (size_t i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << ' ';
	arr3 = arr2;
	std::cout << "\nContents of arr3 after assignment: ";
	for (size_t i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << ' ';
	std::cout << std::endl;
	try
	{
		arr3[10] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
