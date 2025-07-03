#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>


class ScalarConverter{
    private:
        
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter &other);
        ScalarConverter operator=(ScalarConverter &other) const;
        static void  convert(std::string input);
};

#endif
