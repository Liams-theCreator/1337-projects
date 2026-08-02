#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {};

const std::string Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::increment()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
};

void Bureaucrat::decrement()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low\n";
}

void Bureaucrat::signForm(Form &fm)
{
    try
    {
        fm.beSigned(*this);
        std::cout << getName() << " signed " << fm.getName() << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << getName() << " couldn't sign " << fm.getName() << " because " << e.what();
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}