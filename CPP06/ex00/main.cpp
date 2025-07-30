#include "ScalarConverter.hpp"

int main(int ac, char **av){
    (void)ac;
    try
    {
        if(ac == 2)
            ScalarConverter::convert(av[1]);
        else
            std::cout << "There must be 2 arguments." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}