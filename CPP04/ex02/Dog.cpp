#include "Dog.hpp"

Dog::Dog():Animal(){
    std::cout << "Dog Default Constructor." << std::endl;
    brain = new Brain();
    type = "Dog";
}

Dog::~Dog(){
    std::cout << "Dog Destructor Constructor." << std::endl;
    if(brain)
        delete brain;
}


Dog::Dog(const Dog &other):Animal(other){
    std::cout << "Dog Copy Constructor." << std::endl;
    brain = new Brain();
    *this = other;
}

Dog& Dog::operator=(const Dog &other){
    std::cout << "Dog Assignment Operator Overload." << std::endl;
    if(this != &other){
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog WOOFS." << std::endl;
}

std::string Dog::getIdea(int idx) const{
    if(idx < 0 || idx > 99){
        std::cout << "Index out of range for getting ideas" << std::endl;
        return NULL;
    }
    return (brain->getIdeas(idx));
}

void Dog::setIdea(int idx, std::string idea) const{
    if(idx < 0 || idx > 99){
        std::cout << "Index out of range for setting ideas" << std::endl;
        return ;
    }
    brain->setIdeas(idx, idea);
}