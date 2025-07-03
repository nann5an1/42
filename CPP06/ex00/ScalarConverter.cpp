#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    
}

~ScalarConverter();
ScalarConverter(ScalarConverter &other);
ScalarConverter operator=(ScalarConverter &other) const;
static void  convert(std::string input);