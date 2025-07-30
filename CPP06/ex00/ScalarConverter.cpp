#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
    *this = other;
}

ScalarConverter& ScalarConverter ::operator=(const ScalarConverter &other){
    (void)other;
    return *this;
}

void ScalarConverter :: convert(std::string input){
    ScalarConverter sc;
    int input_type = -1;

    const char *str_input = input.c_str();
    int converted_int = atoi(str_input);        //int conversion

    //infinity indication
    if(!input.compare(0, 3, "inf") || !input.compare(0, 4, "+inf") || (!input.compare(0, 4, "-inf")) || (!input.compare(0, 4, "inff")) || (!input.compare(0, 5, "+inff"))  || (!input.compare(0, 5, "-inff"))){
        sc.switchHandler(5, input);
        return ;
    }
    if(input == "nan" || input == "nanf"){
        sc.switchHandler(4, input);
        return ;
    }
    //****other input handling (double)****
    if(input.length() != 1 && input != "f"){
        for(size_t i = 0; i < input.length(); i++){
            if((input[i] != 'F' && input[i] >= 65 && input[i] <= 90) || (input[i] != 'f' && input[i] >= 97 && input[i] <= 122)){
                std::cout << "Invalid Type: Alphabets mixed with digits" << std::endl;
                return ;
            }
        }
    }
    else if(input.length() == 1 && input == "f"){
        std::cout << "Invalid Type: only 1 'f' inputted" << std::endl;
        return ;
    }
    
    //****float handling****
    size_t found = -1;
    int count_dec = 0;
    found = input.find("f");
    std::string new_input;

    if(found != std::string::npos){
        new_input = input.substr(found + 1, input.length() - found - 1); //update the rest of the string to the new input for other checks
        input = input.substr(0, found + 1); //update the first correct path of the float (will only contain 1 'f')
    }

    //handling the first half
    for(size_t i = 0; i < input.length(); i++){
        if(((input[i + 1] == 'f' || input[i + 1] == 'F') && ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)))){
            std::cout << "Invalid Type: alphabets with 'f'" << std::endl;
            return ;
        }
        if(input[i] == '.')
            count_dec += 1;
    }
    if(count_dec > 1){
        std::cout << "Invalid Type:  Repeated decimal" << std::endl;
        return ;
    }

    //handling the sec half
    if(!new_input.empty()){
        std::cout << "Invalid Type: Trailings after 'f'" << std::endl;
        return ;
    }

    // std::cout << "input is now " << input << std::endl;
    // std::cout << "new input is now " << new_input << std::endl;
    // std::cout << "f found at " << found << std::endl;

    
    if(input.empty()){ //if empty string
        std::cout << "Invalid Types" << std::endl;
        return ;
    }
        
    if(input.length() == 1 && !isdigit(input[0])) //char indication
        input_type = 0;
    else if(input.find(".") != std::string::npos){  //double indication
        if(input.find("f") != std::string::npos){ 
            sc.switchHandler(2, input);
            return;
        }
        input_type = 3; 
    }
    else if (converted_int >= INT_MIN && converted_int <= INT_MAX) //int indication
        input_type = 1;
   
    sc.switchHandler(input_type, input);
    return ;
}


void ScalarConverter :: switchHandler(int input_type, std::string input){
    switch (input_type)
    {
     case 0: //input is char type
        char_print(input);
         break;
     case 1: //input is int type
        int_print(input);
         break;
     case 2: //input is float type
        float_print(input);
        break;
     case 3: //input is double type
         double_print(input);
         break;
     case 4: //input type 'nan'
        nan_print(input);
        break;
     case 5: //input type 'inf'
        inf_print(input);
    }
}

int ScalarConverter::getPrecision(std::string &input){
    int precision;
    int len = input.length(); //12.000    //12.f?
    int pos = input.find(".");
    if(input[pos] == '.' && input[pos + 1] == 'f')
        return 2;
    precision = (len - pos) - 1;
    return precision;
}

void ScalarConverter :: char_print(std::string &input){
     std::cout << "char: " << input << std::endl;
    input == "0" 
    ? std::cout << "int: Non displayable \n" 
    : std::cout << "int: " << static_cast<int>(input[0]) << "\n";
    std::cout << "float: Non displayable \n"
              << "double: Non displayable " << std::endl;
}

void ScalarConverter :: int_print(std::string &input){
    input.length() == 1 && input != "0"
    ? std::cout << "char: " << static_cast<char>(input[0] + '0') << "\n"
    : std::cout << "char: Non displayable \n";

    int atoied = atoi(input.c_str());
    std::cout << "int: " << atoied << "\n"
              << "float: " << std::fixed << std:: setprecision(1) << static_cast<float>(atoied) << "f\n"
              << "double: " << static_cast<double>(atoi(input.c_str())) << std::endl;
}


void ScalarConverter::float_print(std::string &input) {
    float float_num;
    std::stringstream str_to_float(input);
    str_to_float >> float_num;

    int atoied = static_cast<int>(float_num);
    int precision = getPrecision(input);
    std::cout << "char: '*'\n"
              << "int: " << atoied << "\n"
              << "float: " << std::fixed << std::setprecision(precision - 1) << float_num << "f\n"
              << "double: " << static_cast<double>(float_num) << std::endl;
}

//havent handled the double literals like 0.0, -4.2
void ScalarConverter :: double_print(std::string &input){
    double double_num;
    std::stringstream str_to_double(input);
    str_to_double >> double_num;
    int precision = getPrecision(input);

    for(size_t i = 0; i < input.length(); i++){
        if(input[i] == '.' && !input[i+1])
            precision = 1;
    }
    
    int atoied = static_cast<int>(double_num);
    std::cout << "char: Non displayable \n"
              << "int: " << atoied << "\n"
              << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(double_num)  << "f\n" 
              << "double: " << double_num << std::endl;

}

void ScalarConverter :: nan_print(std::string &input){
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: " << input << "f\n"
              << "double: " << input << std::endl;

}

void ScalarConverter :: inf_print(std::string &input){
    if(input[0] == '-')
    {
        std::cout << "char: impossible\n"
                    << "int: impossible \n"
                    << "float: -inff \n"
                    << "double: -inf " << std::endl;
        return ;
    }
    std::cout << "char: impossible\n"
              << "int: impossible \n"
              << "float: +inff \n"
              << "double: +inf " << std::endl;
    return ;

}


//types
/*
char: 0
int: 1
float: 2
double: 3
*/
