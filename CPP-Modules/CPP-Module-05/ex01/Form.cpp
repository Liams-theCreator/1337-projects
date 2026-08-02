#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _gradeSign(1), _gradeExec(1) {}

Form::Form(const Form &o): _name(o._name), _sign(o._sign),  _gradeSign(o._gradeSign), _gradeExec(o._gradeExec) {}

Form::Form(const std::string name, int gradeSign, int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    else if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _sign = other._sign;
    return *this;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too High\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too Low\n";
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSign() const
{
    return _sign;
}
int Form::getGradeSign() const
{
    return _gradeSign;
}
int Form::getGradeExec() const
{
    return _gradeExec;
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _sign = true;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "Form: " << obj.getName() << ", signed: " << obj.getSign() << ", grade to sign: " << obj.getGradeSign() << ", grade to execute: " << obj.getGradeExec();
    return os;
}