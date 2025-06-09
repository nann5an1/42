#include "Cat.hpp"

Cat::Cat():Animal(){
    std::cout << "Cat Default Constructor." << std::endl;
    brain = new Brain();
    type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat Destructor Constructor." << std::endl;
    if(brain)
        delete brain;
}

Cat::Cat(const Cat &other):Animal(other){
    std::cout << "Cat Copy Constructor." << std::endl;
    brain = new Brain();
    *this = other;
}

Cat& Cat::operator=(const Cat &other){
    std::cout << "Cat Assignment Operator Overload." << std::endl;
    if(this != &other){
        if (this->brain) 
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat MEOWS." << std::endl;
}

std::string Cat::getIdea(int idx) const{
    if(idx < 0 || idx > 99){
        std::cout << "Index out of range for getting ideas" << std::endl;
        return NULL;
    }
    return (brain->getIdeas(idx));
}

void Cat::setIdea(int idx, std::string idea) const{
    if(idx < 0 || idx > 100){
        std::cout << "Index out of range for setting ideas" << std::endl;
        return ;
    }
    // std::cout << idx << std::endl;
    brain->setIdeas(idx, idea);
}
