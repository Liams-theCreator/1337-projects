#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*creators[3])(const std::string) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return creators[i](target);
        }
    }
    
    std::cout << "Error: form name \"" << formName << "\" does not exist" << std::endl;
    return NULL;
}