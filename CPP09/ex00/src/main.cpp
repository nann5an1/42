#include "../inc/BitcoinExchange.hpp"

int main(int ac, char** av){
    
    try{
        if(ac != 2)
            throw std::runtime_error("Arguments must be 2 with file name");
        BitcoinExchange btc(av[1]); //take the file input
        
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
}