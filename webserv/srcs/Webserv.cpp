#include "../include/Webserv.hpp"

Webserv::Webserv(){}

Webserv::~Webserv(){}
Webserv::Webserv(const Webserv &other){
    (void)other;
}

Webserv& Webserv:: operator=(const Webserv &other){
    (void)other;
    return *this;
}

void Webserv::watchServer(){
    // while(epoll())
}

void Webserv::fileParser(char *av){
    std::string word;
    std::string config_file;
    if(av) config_file = av;
    else config_file = "def.conf";

    std::ifstream file(config_file.c_str());

    std::cout << config_file << std::endl;
    std::string line;

    if(file.is_open()){
        std::cout << "File is opened now" << std::endl;
            while(getline(file, line)){ //read line by line
            // std::cout << line << std::endl;
            if(line.find("server_name") != std::string::npos){
                int space = line.find(" ");
                std::string server_name = line.substr(space + 1, line.length() - space);
                std::cout << server_name << std::endl;
            }
            }
    }
}