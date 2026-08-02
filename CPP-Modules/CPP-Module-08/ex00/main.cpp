#include "easyfind.hpp"

int main()
{
	// --- vector ---
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 1);
		std::cout << "vector: found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "vector: " << e.what();
	}

	// --- list ---
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "list: found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "list: " << e.what();
	}

	return 0;
}