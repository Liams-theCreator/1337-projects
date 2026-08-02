#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
		long n;
		char extra;

		if (!(iss >> n) || (iss >> extra) || n < 0 || n > INT_MAX)
			throw std::runtime_error("Error");
		if (std::find(vec.begin(), vec.end(), static_cast<int>(n)) != vec.end())
			throw std::runtime_error("Error");

		vec.push_back(static_cast<int>(n));
		deq.push_back(static_cast<int>(n));
    }
}
static std::vector<std::pair<int, int> > makePairs(const std::vector<int> &input)
{
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int big = input[i];
		int small = input[i + 1];
		if (small > big)
		{
			big = input[i + 1];
			small = input[i];
		}
		pairs.push_back(std::make_pair(big, small));
	}
	return pairs;
}

static std::vector<int> getWinners(const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);
	return winners;
}

static std::vector<int> orderPend(const std::vector<int> &sortedWinners, const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> pendChain;
	for (size_t i = 0; i < sortedWinners.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == sortedWinners[i])
			{
				pendChain.push_back(pairs[j].second);
				break;
			}
		}
	}
	return pendChain;
}

static std::vector<size_t> generateSeq(size_t n)
{
    std::vector<size_t> order;
    size_t Prev = 1;
    size_t Curr = 3;

    while (Prev < n)
    {
        size_t Start = Curr;
        if (Start > n)
            Start = n;
		
        for (size_t i = Start; i > Prev; --i)
            order.push_back(i - 1);

        size_t Next = Curr + 2 * Prev;
        Prev = Curr;
        Curr = Next;
    }
    return order;
}
static void mergeInsertVector(std::vector<int> &input)
{
	if (input.size() < 2)
		return;

	int leftover = 0;
	bool hasLeftover = false;
	if (input.size() % 2 == 1)
	{
		hasLeftover = true;
		leftover = input.back();
	}

	std::vector<std::pair<int, int> > pairs = makePairs(input);
	std::vector<int> winners = getWinners(pairs);

	mergeInsertVector(winners);

	std::vector<int> mainChain = winners;
	std::vector<int> pendChain = orderPend(winners, pairs);

    mainChain.insert(mainChain.begin(), pendChain[0]);
    std::vector<size_t> order = generateSeq(pendChain.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        int value = pendChain[idx];
        std::vector<int>::iterator bound = std::lower_bound(mainChain.begin(), mainChain.end(), winners[idx]);
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, value);
        mainChain.insert(pos, value);
    }

    if (hasLeftover)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }

    input = mainChain;
}

void PmergeMe::sortVector()
{
    mergeInsertVector(vec);
}

// deque

static std::deque<std::pair<int, int> > makePairsDeque(const std::deque<int> &input)
{
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		int big = input[i];
		int small = input[i + 1];
		if (small > big)
		{
			big = input[i + 1];
			small = input[i];
		}
		pairs.push_back(std::make_pair(big, small));
	}
	return pairs;
}

static std::deque<int> getWinnersDeque(const std::deque<std::pair<int, int> > &pairs)
{
	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].first);
	return winners;
}

static std::deque<int> orderPendDeque(const std::deque<int> &sortedWinners, const std::deque<std::pair<int, int> > &pairs)
{
	std::deque<int> pendChain;
	for (size_t i = 0; i < sortedWinners.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == sortedWinners[i])
			{
				pendChain.push_back(pairs[j].second);
				break;
			}
		}
	}
	return pendChain;
}

static void mergeInsertDeque(std::deque<int> &input)
{
	if (input.size() < 2)
		return;

	int leftover = 0;
	bool hasLeftover = false;
	if (input.size() % 2 == 1)
	{
		hasLeftover = true;
		leftover = input.back();
	}
	std::deque<std::pair<int, int> > pairs = makePairsDeque(input);
	std::deque<int> winners = getWinnersDeque(pairs);

	mergeInsertDeque(winners);

	std::deque<int> mainChain = winners;
	std::deque<int> pendChain = orderPendDeque(winners, pairs);

	mainChain.push_front(pendChain[0]);
	std::vector<size_t> order = generateSeq(pendChain.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		int value = pendChain[idx];
		std::deque<int>::iterator bound = std::lower_bound(mainChain.begin(), mainChain.end(), winners[idx]);
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, value);
		mainChain.insert(pos, value);
	}

	if (hasLeftover)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	input = mainChain;
}

void PmergeMe::sortDeque()
{
	mergeInsertDeque(deq);
}

static double nowMicro()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::run(int ac, char **av)
{
	parse(ac, av);

	std::cout << "Before:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	double startVec = nowMicro();
	sortVector();
	double endVec = nowMicro();

	double startDeq = nowMicro();
	sortDeque();
	double endDeq = nowMicro();

	std::cout << "After:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << (endVec - startVec) << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << (endDeq - startDeq) << " us" << std::endl;
}