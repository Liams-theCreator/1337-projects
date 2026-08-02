#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <algorithm>
#include <utility>
#include <cstddef>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int>  deq;

		void parse(int ac, char **av);
		void sortVector();
		void sortDeque();
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int ac, char **av);
};

#endif
