#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &)
{
	return *this;
}

RPN::~RPN() {}

static bool isOperator(const std::string &tok)
{
	return tok == "+" || tok == "-" || tok == "*" || tok == "/";
}

int RPN::evaluate(const std::string &expr)
{
	std::stack<int> st;
	std::istringstream iss(expr);
	std::string tok;

	while (iss >> tok)
	{
		if (tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9')
			st.push(tok[0] - '0');
		else if (isOperator(tok))
		{
			if (st.size() < 2)
				throw std::runtime_error("Error");
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if (tok == "+")
				st.push(a + b);
			else if (tok == "-")
				st.push(a - b);
			else if (tok == "*")
				st.push(a * b);
			else
			{
				if (b == 0)
					throw std::runtime_error("Error");
				st.push(a / b);
			}
		}
		else
			throw std::runtime_error("Error");
	}

	if (st.size() != 1)
		throw std::runtime_error("Error");
	return st.top();
}
