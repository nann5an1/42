#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default Constructor" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain Detructor" << std::endl;
}

Brain::Brain(const Brain &other){
    std::cout << "Brain Copy Constructor" << std::endl;
}

Brain& Brain::operator=(const Brain &other){
    std::cout << "Brain Assignment Operator Overload" << std::endl;
    return *this;
}