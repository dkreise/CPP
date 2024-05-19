#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- MAIN FROM SUBJECT: ---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	
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
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- EQUIPPING DIFFERENT TYPES OF MATERIA: ---" << std::endl;
	    AMateria* m1 = new Ice();
	    AMateria* m2 = new Cure();
	    Cure* c1 = new Cure();
	    Ice* i1 = new Ice();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(m1);
	    di->equip(m2);
	    di->equip(c1);
	    di->equip(i1);

	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    delete di;
	    delete bob;	
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- EQUIPPING THE SAME OBJECT AND USING UNEXISTING: ---" << std::endl;
	    AMateria* m1 = new Ice();
	    Cure* c1 = new Cure();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(m1);
	    di->equip(m1);
	    di->equip(c1);
	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(3, *bob);
	    di->use(7, *bob);

	    delete di;
	    delete bob;	
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- EQUIPPING MORE THAN 4 MATERIAS: ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	    di->equip(c2);
	    di->equip(c3);
	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    delete di;
	    delete bob;
	    delete c2;
	    delete c3;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- UNEQUIPPING AND WRONG UNEQUIPPING: ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    ICharacter* di = new Character("Di");
	    ICharacter* bob = new Character("bob");
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	   	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    di->unequip(0);
	    di->unequip(2);
	    di->unequip(2);
	    di->unequip(7);

	    di->equip(c2);
	    di->equip(c3);

	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    delete di;
	    delete bob;
	    delete i1;
	    delete i3;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- CHECKING IF CHARACTER'S COPIES ARE DEEP (WITH '='): ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    Character* di = new Character("Di");
	    Character* bob = new Character("bob");
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	   	    
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    *bob = *di;

	    di->unequip(0);
	    di->unequip(2);
	    di->equip(c2);
	    di->equip(c3);

	    std::cout << "--- use() of di:" << std::endl;
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    std::cout << "--- use() of bob (now his name is also Di):" << std::endl;
	    bob->use(0, *di);
	    bob->use(1, *di);
	    bob->use(2, *di);
	    bob->use(3, *di);

	    delete i1;
	    delete i3;
	    delete di;
	    delete bob;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- CHECKING IF CHARACTER'S COPIES ARE DEEP (WITH COPY CTOR): ---" << std::endl;
	    Ice* i1 = new Ice();
	    Ice* i2 = new Ice();
	    Ice* i3 = new Ice();
	    Cure* c1 = new Cure();
	    Cure* c2 = new Cure();
	    Cure* c3 = new Cure();
	    Character* di = new Character("Di");
	    
	    di->equip(i1);
	    di->equip(i2);
	    di->equip(i3);
	    di->equip(c1);
	   	    
	   	Character* bob = new Character(*di);

	    di->unequip(0);
	    di->unequip(2);
	    di->equip(c2);
	    di->equip(c3);

	    std::cout << "--- use() of di:" << std::endl;
	    di->use(0, *bob);
	    di->use(1, *bob);
	    di->use(2, *bob);
	    di->use(3, *bob);

	    std::cout << "--- use() of bob (now his name is also Di):" << std::endl;
	    bob->use(0, *di);
	    bob->use(1, *di);
	    bob->use(2, *di);
	    bob->use(3, *di);

	    delete i1;
	    delete i3;
	    delete di;
	    delete bob;
	}
	{
		std::cout << "----------------------------------------------------" << std::endl;
	    std::cout << "--- : ---" << std::endl;
		MateriaSource* src = new MateriaSource();
		Ice* i1 = new Ice();

		src->learnMateria(i1);
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());

			
		delete src;
	}

	return (0);
}