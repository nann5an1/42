#include "iMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource(); //will call the constructor of MateriaSource
    src->learnMateria(new Ice()); //constructor of Ice called
    src->learnMateria(new Cure()); //constructor of Cure called
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}