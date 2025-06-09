#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    // private:
    //     std::string idea;
    public:
        std::string ideas[100];
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
        std::string getIdeas(int idx);
        void setIdeas(int idx, const std::string &idea);
};

#endif
