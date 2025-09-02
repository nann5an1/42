#include "../inc/BitcoinExchange.hpp"

int main(int ac, char** av){
    
    try{
        if(ac != 2)
            throw std::runtime_error("Error: could not open file.");
        BitcoinExchange btc(av[1]); //take the file input
        
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    
}