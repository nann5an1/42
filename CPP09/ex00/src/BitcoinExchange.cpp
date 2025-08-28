#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(char *filename){
    std::string line;
    std::fstream file(filename);
    // bool flag = false;
    // std::ofstream output("output.txt");
    if(file.fail())
        throw std::runtime_error("File does not exist");
    std::getline(file, line);  //get the first line of the file
    if(line.find("date | value") == std::string::npos)
        throw std::runtime_error("Invalid file format");

    while(std::getline(file, line)){ //read the whole file
        if(line.find("|") != std::string::npos){
            
        }
        std::cout << line << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}
