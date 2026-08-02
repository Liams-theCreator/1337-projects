#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>
#include <algorithm>
#include <numeric>

class Span
{
	private:
		unsigned int      maxSize;
		std::vector<int>  data;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void         addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename it>
		void addRange(it first, it last);

		class FullException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

template <typename it>
void Span::addRange(it first, it last)
{
	if (data.size() + std::distance(first, last) > maxSize)
		throw FullException();
	data.insert(data.end(), first, last);
}

#endif