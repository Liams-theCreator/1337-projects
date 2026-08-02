#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 137);
        ShrubberyCreationForm form1("home");
        
        std::cout << form1 << std::endl;
        alice.signForm(form1);
        alice.executeForm(form1);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }
    
    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 45);
        RobotomyRequestForm form2("Bender");
        
        std::cout << form2 << std::endl;
        bob.signForm(form2);
        bob.executeForm(form2);
        bob.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }
    
    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 5);
        PresidentialPardonForm form3("Criminal");
        
        std::cout << form3 << std::endl;
        charlie.signForm(form3);
        charlie.executeForm(form3);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }
    
    std::cout << "\n=== Test 4: Grade too low to execute ===" << std::endl;
    try
    {
        Bureaucrat dave("Dave", 150);
        ShrubberyCreationForm form4("garden");
        
        dave.signForm(form4);
        dave.executeForm(form4);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 5: Form not signed ===" << std::endl;
    try
    {
        Bureaucrat eve("Eve", 1);
        PresidentialPardonForm form5("Target");
        
        eve.executeForm(form5);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }
    
    return 0;
}