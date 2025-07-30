#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <float.h>
#include <stdio.h>
#include <limits.h>

class ScalarConverter{
 
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter &other) ;
        static void  convert(std::string input);

        void char_print(std::string &input);
        void int_print(std::string &input);
        void float_print(std::string &input);
        void double_print(std::string &input);
        void nan_print(std::string &input);
        void inf_print(std::string &input);
        void switchHandler(int intput_type, std::string input);
        int getPrecision(std::string &input);
};

#endif
