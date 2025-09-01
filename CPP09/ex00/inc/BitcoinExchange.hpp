#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits.h>
#include <stdlib.h>
#include <map>

class BitcoinExchange{
    private:
        int value_check(std::string token);
        std::string identify_date(std::string token);
    public:
        BitcoinExchange();
        BitcoinExchange(char *filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        // BitcoinExchange& operator=(const BitcoinExchange& other);


        // void run(std::string &filename);
};

class FormatException : public std::exception{
    public:
        const char* what() const throw(){
            return ("FormatException: Wrong format in csv.");
        }
};

#endif