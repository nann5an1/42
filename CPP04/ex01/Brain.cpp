#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default Constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Other thoughts";
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

std::string Brain::getIdeas(int idx){
    return (ideas[idx]);
}

void Brain::setIdeas(int idx, const std::string &idea){
    if(idx >= 0 && idx < 100){
        std::cout << "Ideas added to index " << idx << std::endl;
        ideas[idx] = idea;
    }
    else
        std::cout << "Index out of bounds" << std::endl;
}