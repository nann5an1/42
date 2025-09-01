#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(char *filename){
    std::multimap <std::string, int> map_db;
    std::string token;
    std::string line;
    std::fstream file(filename);
    int col_count = 0;
    

    
    // std::ofstream output("output.txt");
    if(file.fail())
        throw std::runtime_error("File does not exist");
    std::getline(file, line);

    int found = line.find("date | value"); //check if the header is correct
    if(found  < 0)
        throw FormatException();

    while(std::getline(file, line)){ //read the whole file
        std::stringstream ss(line);
        std::string date;

        // //read each token in the line
        //data processing into map_db
        while(ss >> token){
            switch (col_count){
            case 0:{
                date = identify_date(token);
                break;  
            }
            case 1:
                // std::cout << token << std::endl;
                break;
            case 2:{
                map_db.insert(std::pair<std::string, int>(date, value_check(token)));
                break;
            } 
            }
            
            col_count++;
        }
        col_count = 0;
        
    }
    for (std::multimap<std::string, int>::iterator it = map_db.begin(); it != map_db.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
        }
}
        


BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

std::string BitcoinExchange::identify_date(std::string token){
    struct tm tm;
    char* result = strptime(token.c_str(), "%Y-%m-%d", &tm); //will attempt to convert to the format

    if(result != NULL && *result == '\0')
        return token;
    else
        return "date error";
    return token;
}


int BitcoinExchange::value_check(std::string token){
    double value = strtod(token.c_str(), NULL);
    // std::cout << value << std::endl;
    
    if(value > INT_MAX || value < INT_MIN)
        return -2;
    else if(value < 0)
        return (std::cerr << "Error: not a positive number." << std::endl, -2);

    return value;
}