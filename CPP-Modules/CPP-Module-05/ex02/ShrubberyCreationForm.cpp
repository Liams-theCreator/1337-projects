#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const
{
    std::string filename = _target + "_shrubbery";

    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not create file");
    file << executor.getName() << " planted:\n\n";
file << "      *\n";
file << "     ***\n";
file << "    *****\n";
file << "   *******\n";
file << "  *********\n";
file << "   *******\n";
file << "    *****\n";
file << "   *******\n";
file << "  *********\n";
file << " ***********\n";
file << "  *********\n";
file << "    *****\n";
file << "      |\n";
file << "      |\n";
    
    file.close();
}