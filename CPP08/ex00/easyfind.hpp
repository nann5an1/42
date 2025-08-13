#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <cstdlib>
#include <ctime>

class number_not_found : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "Number not found in the container";
    }
};


#endif