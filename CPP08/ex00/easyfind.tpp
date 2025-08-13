#include "easyfind.hpp"

template <typename T>
void easyfind(T &container, int n){ //assuming T is the container of integers 
    typename T::iterator it;
    bool flag = false;
    for(it = container.begin(); it != container.end(); ++it){
        if(n == *it)
        {
            std::cout << "Found " << n << " in the container." << std::endl;
            flag = true;
            return;
        }
    }
    if(!flag)
        throw number_not_found();
}