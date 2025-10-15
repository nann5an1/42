#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define life_cell '0'
#define dead_cell ''

void gol(int width, int height, int iterations);

#endif