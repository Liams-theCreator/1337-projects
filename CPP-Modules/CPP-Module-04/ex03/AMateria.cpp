#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target) 
{
    std::cout << "Using AMateria on " << target.getName() << "\n";
}