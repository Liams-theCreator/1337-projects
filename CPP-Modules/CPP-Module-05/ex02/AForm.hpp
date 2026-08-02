#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExec; 
    public:

    AForm();
    AForm(const AForm &other);
    AForm(const std::string name, int gradeSign, int gradeExec);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

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
    void execute(const Bureaucrat &executor) const;

    protected:
        virtual void executeAction(const Bureaucrat &executor) const = 0;
};


std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif