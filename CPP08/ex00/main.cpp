#include "easyfind.hpp"
#include "easyfind.tpp"

int main(){
    srand(time(0)); // Seed for random number generation
    std::vector<int> vec;
    for(int i = 0; i < 10; ++i)
        vec.push_back(rand() % 20);

    try
    {
        easyfind(vec, 5); 
        easyfind(vec, 15);
        easyfind(vec, 10); // This will throw an exception since 8 is not in the vector
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}