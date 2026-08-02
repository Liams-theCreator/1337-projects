#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExec; 
    public:

    Form();
    Form(const Form &other);
    Form(const std::string name, int gradeSign, int gradeExec);
    Form &operator=(const Form &other);
    ~Form();

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    std::string getName() const;
    bool getSign() const;
    int getGradeSign() const;
    int getGradeExec() const;

    void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif