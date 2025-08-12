#include <iostream>
#include <stdlib.h>
#include "Array.hpp"
#define MAX_VAL 100

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
    //uncomment this
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cout << "didn't saved the same value!!" << std::endl;
    //         return 1;
    //     }
    //     else
    //         std::cout << "saved the same value \n" << numbers[i] << std::endl;
    // }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//

     Array<int> arr(5); //using template of class Array with int type calling constructor with size parameter
    std::cout<< "Array size:" << arr.size() << std::endl;
    for(unsigned int i = 0; i < arr.size(); i++)
        std::cout << "arr[i] " << arr[i] << std::endl;

    Array<int> arr2(6); //using copy constructor
    for(unsigned int i = 0; i < arr2.size(); i++){
        arr2[i] = i + 2; //calls out the subsript operator[]
        std::cout << "arr2[i] " << arr2[i] << std::endl;
    }

    Array<int> arr3(arr2); //using copy constructor
    std::cout << "arr3 size: " << arr3.size() << std::endl;

    Array<int> arr4 = arr2; //using assignment operator
    try
    {
        std::cout << "arr4 size: " << arr4.size() << std::endl;
        std::cout << "arr4[6] = " << arr4[6] << std::endl; //throw exception index out of range
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Array<int> arr5;
    std::cout << "arr5 size : " << arr5.size() << std::endl;

}