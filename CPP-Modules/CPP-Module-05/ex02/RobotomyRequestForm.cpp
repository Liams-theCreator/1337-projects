#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction(const Bureaucrat &executor) const
{
    std::cout << "Drilling : ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZNNNNN" << std::endl;
    
    if (rand() % 2 == 0)
        std::cout << executor.getName() << " has robotomized " << _target << " successfully !" << std::endl;
    else
        std::cout << "Robotomy of " << _target << " failed." << std::endl;
}