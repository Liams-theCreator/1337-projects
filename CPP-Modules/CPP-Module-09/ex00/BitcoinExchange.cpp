#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		data = other.data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string &s)
{
	std::string::size_type a = s.find_first_not_of(" \t\r\n");
	std::string::size_type b = s.find_last_not_of(" \t\r\n");
	if (a == std::string::npos)
		return "";
	return s.substr(a, b - a + 1);
}

static bool validDate(const std::string &d)
{
	if (d.size() != 10 || d[4] != '-' || d[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
		if (i != 4 && i != 7 && (d[i] < '0' || d[i] > '9'))
			return false;

	int year = std::atoi(d.substr(0, 4).c_str());
	int month = std::atoi(d.substr(5, 2).c_str());
	int day = std::atoi(d.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1)
		return false;

	int maxDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int limit = maxDay[month - 1];
	if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)))
		limit = 29;
	return day <= limit;
}

static bool isDataLine(const std::string &line)
{
	std::string::size_type bar = line.find('|');
	if (bar == std::string::npos)
		return false;
	return validDate(trim(line.substr(0, bar)));
}

static double rateFor(const std::map<std::string, double> &data, const std::string &date)
{
	std::map<std::string, double>::const_iterator it = data.lower_bound(date);
	if ((it == data.end() || it->first != date) && it != data.begin())
		--it;
	return it->second;
}

bool BitcoinExchange::GetDB(const std::string &path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type c = line.find(',');
		if (c != std::string::npos)
			data[line.substr(0, c)] = std::atof(line.substr(c + 1).c_str());
	}
	return true;
}

void BitcoinExchange::ProcessDB(const std::string &path) const
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	if (isDataLine(line))
	{
		file.clear();
		file.seekg(0);
	}

	while (std::getline(file, line))
	{
		std::string::size_type bar = line.find('|');
		std::string date = "";
		std::istringstream iss;
		double value;
		char extra;

		if (bar != std::string::npos)
		{
			date = trim(line.substr(0, bar));
			iss.str(trim(line.substr(bar + 1)));
		}

		if (bar == std::string::npos || !validDate(date) || !(iss >> value) || (iss >> extra))
			std::cout << "Error: bad input => " << line << std::endl;
		else if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << date << " => " << value << " = " << value * rateFor(data, date) << std::endl;
	}
}
