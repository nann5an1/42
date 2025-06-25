#include "Intern.hpp"
#include <ctype.h>

Intern::Intern(){
    std::cout << "Intern Def Constructor" << std::endl;
}

Intern::~Intern(){
    std::cout << "Intern Destructor" << std::endl;
}

Intern::Intern(Intern &other){
    *this = other;
}

Intern& Intern::operator=(Intern &other){
    (void)other;
    return *this;
}


AForm *Intern::makeForm(std::string formName, std::string target){
    AForm *form = NULL;
    int indicator = -1;
    std::string name_str = "";

    std::string form_array[3] = {"presidential", "robotomy", "shrubbery"};
    for(int i= 0 ; i < (int)formName.length(); i++)
        name_str += tolower(formName[i]); //robotomy request

    for (int i = 0; i < 3; i++)
    {
       if (name_str.find(form_array[i]) != std::string::npos){
        indicator = i;
        std::cout << "Intern creates " << formName << std::endl;
        break;
       }
    }

    if (indicator == -1){
        return NULL;
        throw InternFormException();
    }
    
    switch (indicator)
    {
    case 0:
        form = new PresidentialPardonForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        form = new ShrubberyCreationForm(target);
        break;
    default:
        break;
    }
    return (form);
}