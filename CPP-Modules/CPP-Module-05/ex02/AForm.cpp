#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _sign(false), _gradeSign(1), _gradeExec(1) {}

AForm::AForm(const AForm &o): _name(o._name), _sign(o._sign), _gradeSign(o._gradeSign), _gradeExec(o._gradeExec) {}

AForm::AForm(const std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _sign = other._sign;
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too High\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too Low\n";
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSign() const
{
    return _sign;
}
int AForm::getGradeSign() const
{
    return _gradeSign;
}
int AForm::getGradeExec() const
{
    return _gradeExec;
}

void AForm::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _sign = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_sign)
        throw GradeTooLowException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();

    executeAction(executor);
}


std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "Form: " << obj.getName() << ", signed: " << obj.getSign() << ", grade to sign: " << obj.getGradeSign() << ", grade to execute: " << obj.getGradeExec();
    return os;
}