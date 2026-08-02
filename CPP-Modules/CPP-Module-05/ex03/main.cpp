#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    
    std::cout << "=== Test 1: Intern creates ShrubberyCreationForm ===" << std::endl;
    {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "garden");
        
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat alice("Alice", 137);
            alice.signForm(*form);
            alice.executeForm(*form);
            
            delete form;
        }
    }
    
    std::cout << "\n=== Test 2: Intern creates RobotomyRequestForm ===" << std::endl;
    {
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Bender");
        
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat bob("Bob", 45);
            bob.signForm(*form);
            bob.executeForm(*form);
            
            delete form;
        }
    }
    
    std::cout << "\n=== Test 3: Intern creates PresidentialPardonForm ===" << std::endl;
    {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Criminal");
        
        if (form)
        {
            std::cout << *form << std::endl;
            
            Bureaucrat charlie("Charlie", 5);
            charlie.signForm(*form);
            charlie.executeForm(*form);
            
            delete form;
        }
    }
    
    std::cout << "\n=== Test 4: Intern tries to create invalid form ===" << std::endl;
    {
        Intern intern;
        AForm* form = intern.makeForm("invalid form", "target");
        
        if (form)
            delete form;
        else
            std::cout << "Form is NULL (as expected)" << std::endl;
    }
    
    std::cout << "\n=== Test 5: Multiple interns, multiple forms ===" << std::endl;
    {
        Intern intern1;
        Intern intern2;
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "park");
        AForm* form2 = intern2.makeForm("robotomy request", "Wall-E");
        
        if (form1 && form2)
        {
            Bureaucrat dave("Dave", 1);
            dave.signForm(*form1);
            dave.signForm(*form2);
            dave.executeForm(*form1);
            dave.executeForm(*form2);
            
            delete form1;
            delete form2;
        }
    }
    
    return 0;
}