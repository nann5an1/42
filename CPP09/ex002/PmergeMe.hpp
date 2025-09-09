#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <limits.h>
#include <utility>
#include <cmath>
#include <sys/time.h>

class PmergeMe {
    private:
        int _pair_count, final_flag;
        std::vector<std::pair<int, int> > pairs, sorted_pairs;
        std::vector<int> vec, input_vec,
        main_chaine, pending_chaine, original_pending, 
        original_main, sorted_main_chaine;
        std::deque<int> deq;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void digit_check(int ac, char **av);
        void execute(int ac, char **av);
        std::vector<int> generate_sequence();
        void time_comparision_output(double duration_deq, double duration_vec);
        int duplicate_check(std::vector<int> &input_vec);

        // print helpers
        template <typename T>
        void print_container(T& container){
        final_flag ? std::cout << "After: " : std::cout << "Before: ";
        
        if(container.size() > 5){
            for(size_t it = 0; it != container.size() - (container.size() - 5); it++)
                std::cout << container[it] << " ";
            std::cout << "[...]" << std::endl;
        }
        else{
            for(size_t it = 0; it != container.size(); it++)
                std::cout << container[it] << " " ;
            std::cout << std::endl;
        }
        
        
    }

        template <typename T>
        void print_pair(T& container) {
            typename T::iterator it;
            std::cout << "Print pair: ";
            for (it = container.begin(); it != container.end(); ++it) {
                std::cout << "[" << it->first << ", " << it->second << "]";
                if (it + 1 != container.end()) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }

        // ford–johnson recursive
        template <typename T>
        T ford_johnson(T& container) {
            if (container.size() <= 1)
                return container;

            std::vector<std::pair<typename T::value_type, typename T::value_type> > local_pairs;
            ford_original_pairs(container, local_pairs);

            T local_main;
            T local_pending;
            ford_separate_pairs(local_pairs, local_main, local_pending);

            T sorted_main = ford_johnson(local_main);

            for (typename T::iterator it = local_pending.begin(); it != local_pending.end(); ++it) {
                typename T::iterator pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), *it);
                sorted_main.insert(pos, *it);
            }
            return sorted_main;
        }

        // pair operations
        template <typename T>
        void separate_pairs(T& container){
            typename T::iterator it;
            for(it = container.begin(); it != container.end(); ++it){
                if(it->second != -1)
                    main_chaine.push_back(it->first);
                if(it->second == -1)
                    pending_chaine.push_back(it->first);
                else
                    pending_chaine.push_back(it->second);
            }
        }

        template <typename T>
        void get_original_pairs(T& container){
            typename T::iterator it;
            _pair_count = 0;
            for(it = container.begin(); it != container.end(); ++it){
                if((it + 1) != container.end()){
                    if(*it < *(it + 1))
                        std::swap(*it, *(it + 1));
                    pairs.push_back(std::make_pair(*it, *(it + 1)));
                    ++it;
                }
                else{
                    pairs.push_back(std::make_pair(*it, -1));
                    break;
                }
                _pair_count++;
            }
        }

        template <typename T>
        void ford_original_pairs(const T& container, std::vector<std::pair<int,int> >& paired) {
            typename T::const_iterator it;
            for (it = container.begin(); it != container.end(); ++it) {
                if ((it + 1) != container.end()) {
                    int a = *it;
                    int b = *(it + 1);
                    if (a < b)
                        std::swap(a, b);
                    paired.push_back(std::make_pair(a, b));
                    ++it;
                } else {
                    paired.push_back(std::make_pair(*it, -1));
                    break;
                }
            }
        }

        template <typename T>
        void ford_separate_pairs(
            const std::vector<std::pair<int,int> >& paired,
            T& main_chain,
            T& pending_chain
        ) {
            typename std::vector<std::pair<int,int> >::const_iterator it;
            for (it = paired.begin(); it != paired.end(); ++it) {
                if(it->second != -1)
                    main_chain.push_back(it->first);
                if(it->second == -1)
                    pending_chain.push_back(it->first);
                else
                    pending_chain.push_back(it->second);
            }
        }

        // jacobsthal helpers
        template <typename T>
        void jacobsthal(T& sorted_main);

        template <typename T>
        void binary_insertion_sort(T& container, int value_to_insert) {
            typename T::iterator pos = std::lower_bound(container.begin(), container.end(), value_to_insert);
            container.insert(pos, value_to_insert);
        }

        template <typename T>
        void sort_container(T& container);
};

class NotANumberException: public std::exception{
    public: const char* what() const throw(){ return "Error: not a number."; }
};
class NotAnIntException: public std::exception{
    public: const char* what() const throw(){ return "Error: not an integer."; }
};
class PositiveNumberException: public std::exception{
    public: const char* what() const throw(){ return "Error: no negative number is allowed."; }
};
class DuplicateNumberException: public std::exception{
    public: const char* what() const throw(){ return "Error: Duplicate number included."; }
};

#endif
