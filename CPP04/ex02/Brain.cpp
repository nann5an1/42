#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default Constructor" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain Detructor" << std::endl;
}

Brain::Brain(const Brain &other){
    std::cout << "Brain Copy Constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other){
    std::cout << "Brain Assignment Operator Overload" << std::endl;
    if(this != &other){
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
}
    return *this;
}


void Brain::setIdeas(const std::string &idea){
    for(int i=0; i< 100; i++)
        ideas[i] = idea;
}