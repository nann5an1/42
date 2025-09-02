#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(char *filename){
    std::map <std::string, double> map_db;
    std::string token;
    std::string line, input_line;
    std::fstream file, input_file;
    
    int col_count = 0;
    int bool_date = 0;
    int value_ret = 0;

    file.open("../data.csv", std::ios::in);
  
    if (!file.is_open())
        std::cerr << "Failed to open file\n";
    
     //taking the csv file into the map
    while(std::getline(file, line)){ //read the whole file
        std::stringstream ss(line);
        std::string date;
        std::string rate_str;

        //data processing into map_db
        int delimeter = line.find(",");
        date = line.substr(0, delimeter);\
        rate_str = line.substr(delimeter + 1, line.size());
        double rate = strtod(rate_str.c_str(), NULL);

        //insert into map
        map_db.insert(std::pair<std::string, double>(date, rate));
    }     
    // for (std::map<std::string, double>::iterator it = map_db.begin(); it != map_db.end(); ++it) {
    //     std::cout << it->first << " => " << std::fixed<< std::setprecision(2) << it->second << std::endl;
    //     }


    //read the input txt file
    input_file.open(filename);
    if(input_file.fail()){
        std::cerr << "File does not exist\n";
        return ;
    }
        
    std::getline(input_file, input_line);
    if (input_line.find("date | value") == std::string::npos)
        std::cout << "Error: bad input => " << input_line << std::endl;

    //read input file
    while(std::getline(input_file, input_line)){
        std::stringstream ss(input_line); //get each token in the line
        std::string date_token;

         while(ss >> token){
            switch (col_count){
            case 0:{
                bool_date = identify_date(token);
                date_token = token;
                if(!bool_date)
                    std::cout << "Error: bad input => " << token << std::endl;
                break;  
            }
            case 1:{
                if(token != "|")
                    std::cout << "Error: bad format => " << input_line << std::endl;
                 break;
            }
            case 2:{
                value_ret = value_check(token);
                if(value_ret == -1)
                    std::cout << "Error: not a positive number." << std::endl;
                else if(value_ret == -2)
                    std::cout << "Error: too large a number." << std::endl;
                else if(bool_date){
                    map_iteration(map_db, date_token, atoi(token.c_str()));
                }
                break;
            } 
            }
            col_count++;
        }
        col_count = 0;
    }
}
        


BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

int BitcoinExchange::identify_date(std::string token){
    struct tm tm;
    char* result = strptime(token.c_str(), "%Y-%m-%d", &tm); //will attempt to convert to the format

    if(result != NULL && *result == '\0') return 1;
    else return 0;
    return 1;
}


int BitcoinExchange::value_check(std::string token){
    double value = strtod(token.c_str(), NULL);
    // std::cout << value << std::endl;
    
    if(value > INT_MAX || value < INT_MIN) return -2;
    else if(value < 0) return -1;

    return 1;
}

void BitcoinExchange::map_iteration(std::map<std::string, double>& map_db, std::string token, int value) {
    std::map<std::string, double>::iterator it = map_db.lower_bound(token);

    if (it != map_db.end() && it->first == token)
        std::cout << token << " => " << value << " = " << std::fixed << std::setprecision(2) << (it->second * value) << std::endl;
    else {
       --it;
       std::cout << token << " => " << value << " = " << std::fixed << std::setprecision(2) << (it->second * value) << std::endl;
       
    }
}


