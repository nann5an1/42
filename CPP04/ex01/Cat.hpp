#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain* brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);
        void makeSound ()const;
        std::string getIdea(int idx) const;
        void setIdea(int idx, std::string idea) const;
};

#endif