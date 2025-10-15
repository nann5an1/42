#include "life.h"


int main(int ac, char **av){
    if(ac == 4){
        gol(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    }
}