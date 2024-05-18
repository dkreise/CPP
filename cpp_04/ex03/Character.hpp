#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character (Character const & src);
        ~Character(void);

        Character & operator=(Character const & r);

        std::string const & getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string _name;
        AMateria *_slots[4];
};

#endif