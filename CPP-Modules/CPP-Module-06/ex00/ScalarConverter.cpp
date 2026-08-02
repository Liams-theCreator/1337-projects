#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
    (void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static Type getType(const std::string &param)
{
    bool hasDot = false;
    bool hasF = false;
    size_t start = 0;
    size_t i;

    if (param == "nan" || param == "nanf" ||
        param == "+inf" || param == "-inf" ||
        param == "+inff" || param == "-inff")
        return PSEUDO;
    if (param.size() == 1 && !std::isdigit(param[0]) && std::isprint(param[0]))
        return CHAR;
    if (param[0] == '-' || param[0] == '+')
        start = 1;
    if (start == param.size())
        return INVALID;

    for (i = start; i < param.size(); i++)
    {
        if (param[i] == '.')
            hasDot = true;
        else if (param[i] == 'f' && i == param.size() - 1)
            hasF = true;
        else if (!std::isdigit(param[i]))
            return INVALID;
    }
    if (hasDot && hasF)
        return FLOAT;
    if (hasDot && !hasF)
        return DOUBLE;
    if (!hasDot && !hasF)
        return INT;

    return INVALID;
}

static void printChar(double val)
{
    if (val != val || val > 127 || val < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val)
{
    if (val != val || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(double val)
{
    float f = static_cast<float>(val);
    std::cout << "float: " << f;
    if (f == std::floor(f) && val == val && val != std::numeric_limits<float>::infinity() && val != -std::numeric_limits<float>::infinity())
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
}

static void printDouble(double val)
{
    std::cout << "double: " << val;
    if (val == std::floor(val) && val == val && val != std::numeric_limits<double>::infinity() && val != -std::numeric_limits<double>::infinity())
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}

void ScalarConverter::converter(const std::string &param)
{
    Type type = getType(param);
    double val = 0.0;

    if (type == INVALID)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    if (type == PSEUDO)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (param == "nan" || param == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (param == "+inf" || param == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return ;
    }
    if (type == CHAR)
        val = static_cast<double>(param[0]);
    else if (type == INT)
        val = static_cast<double>(std::atoi(param.c_str()));
    else if (type == FLOAT)
        val = static_cast<double>(std::atof(param.c_str()));
    else if (type == DOUBLE)
        val = std::atof(param.c_str());

    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}