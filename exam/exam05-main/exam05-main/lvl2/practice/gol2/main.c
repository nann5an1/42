#include "life.h"

int main(int ac, char **av){
    if(ac != 4)
        return 1;
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iter = atoi(av[3]);

    if(width > 0 && height > 0 && iter >= 0)
        gol(width, height, iter);

}