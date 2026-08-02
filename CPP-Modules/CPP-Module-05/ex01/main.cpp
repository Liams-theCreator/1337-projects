#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // case 1: valid bureaucrat signs a form successfully
    try
    {
        Bureaucrat alice("Alice", 10);
        Form f("Tax Form", 20, 50);
        alice.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }

    // case 2: bureaucrat grade too low to sign
    try
    {
        Bureaucrat bob("Bob", 100);
        Form f("Secret Form", 10, 50);
        bob.signForm(f);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }

    // case 3: invalid form construction
    try
    {
        Form f("Bad Form", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what();
    }

    return 0;
}