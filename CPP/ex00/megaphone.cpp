#include <iostream>
#include <cctype>

int main(int argc, char **argv){
    const char *def = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    if (argc > 1){
        for(int count = 1; count < argc; count++){
            for(char *arg = argv[count] ;*arg; arg++)
                std::cout <<  (char)(std::toupper((int)(*arg)));
            std::cout << " ";
        }
    }
    else
        std::cout << def;
    std::cout << std::endl;
    return (0);
}