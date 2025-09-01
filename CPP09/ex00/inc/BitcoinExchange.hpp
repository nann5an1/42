#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>

class BitcoinExchange{
    public:
        BitcoinExchange();
        BitcoinExchange(char *filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        // void run(std::string &filename);
};

class FormatException : public std::exception{
    public:
        const char* what() const throw(){
            return ("FormatException: Wrong format in csv.");
        }
};

#endif