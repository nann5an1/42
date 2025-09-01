#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(char *filename){
    std::string line;
    std::fstream file(filename);
    // bool flag = false;
    // std::ofstream output("output.txt");
    if(file.fail())
        throw std::runtime_error("File does not exist");
    std::getline(file, line);

    int found = line.find("date | value");
    if(found  < 0)
        throw FormatException();

    while(std::getline(file, line)){ //read the whole file
        std::cout << line.find("|") << std::endl;
            // std::cout << found << std::endl;
        
        std::cout << line << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}
