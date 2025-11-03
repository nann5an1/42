#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>


class Webserv{
    private:
        std::string server_name;
        std::string listen_port;
        std::vector<std::string> error_pages;
        std::string client_max_body_size;
        std::vector<std::pair<std::string, std::string> > locations;
    public:
        Webserv();
        ~Webserv();
        Webserv(const Webserv &other);
        Webserv& operator=(const Webserv &other);
        void watchServer();
        void fileParser(char *av);
};

#endif