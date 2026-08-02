#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest:  " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span one(1);
	one.addNumber(1);
	try
	{
		one.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span big(10000);
	std::vector<int> nums;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 10000; ++i)
		nums.push_back(std::rand());
	big.addRange(nums.begin(), nums.end());
	std::cout << "10k shortest: " << big.shortestSpan() << std::endl;
	std::cout << "10k longest:  " << big.longestSpan() << std::endl;

	return 0;
}

