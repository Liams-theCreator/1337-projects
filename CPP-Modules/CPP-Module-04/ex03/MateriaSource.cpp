#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    int i = 0;
    for ( ; i < 4; i++)
        sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other) 
{
    int i = 0;
    for ( ; i < 4; i++) 
    {
        if (other.sources[i])
            sources[i] = other.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const & other) 
{
    if (this != &other) 
    {
        int i = 0;
        for ( ; i < 4; i++) 
        {
            delete sources[i];
            if (other.sources[i])
                sources[i] = other.sources[i]->clone();
            else
                sources[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    for ( ; i < 4; i++)
        delete sources[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    for ( ; i < 4; i++)
    {
        if (!sources[i])
        {
            sources[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    for ( ; i < 4; i++) 
    {
        if (sources[i] && sources[i]->getType() == type)
            return sources[i]->clone();
    }
    return NULL;
}