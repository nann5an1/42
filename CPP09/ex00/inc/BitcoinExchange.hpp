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
        int identify_date(std::string token);
        void map_iteration(std::map <std::string, double> &map_db, std::string date_token, int val_token);
    public:
        BitcoinExchange();
        BitcoinExchange(char *filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        // BitcoinExchange& operator=(const BitcoinExchange& other);
};

class FormatException : public std::exception{
    public:
        const char* what() const throw(){
            return ("FormatException: Wrong format in csv.");
        }
};

#endif