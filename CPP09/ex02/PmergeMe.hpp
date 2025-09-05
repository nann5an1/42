#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <stdlib.h>
#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <limits.h>
class PmergeMe{
    private:
        std::vector<int> input_vec;
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void digit_check(int ac, char **av);
        void execute(int ac, char **av);
        template <typename T>
        void print_container(T &container){
            typename T::iterator it;
            std::cout << "Before: " << " ";
            for(it = container.begin(); it != container.end(); it++){
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        void print_vec();
        void print_deq();
    
        
};

class NotANumberException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: not a number.";
        }
};

class NotAnIntException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: not an integer.";
        }
};

class PositiveNumberException: public std::exception{
    public:
        virtual const char* what() const throw(){
            return "Error: no negative number is allowed.";
        }
};

#endif