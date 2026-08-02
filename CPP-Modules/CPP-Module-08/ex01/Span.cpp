#include "Span.hpp"

Span::Span(): maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : maxSize(other.maxSize), data(other.data) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		maxSize = other.maxSize;
		data = other.data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (data.size() >= maxSize)
		throw FullException();
	data.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (data.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted(data);
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		unsigned int gap = sorted[i] - sorted[i - 1];
		if (gap < shortest)
			shortest = gap;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (data.size() < 2)
		throw NoSpanException();

	int lo = *std::min_element(data.begin(), data.end());
	int hi = *std::max_element(data.begin(), data.end());
	return hi - lo;
}

const char *Span::FullException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Span need atleast two numbers";
}
