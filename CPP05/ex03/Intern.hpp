#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Intern{
    public:
        Intern();
        ~Intern();
        Intern(Intern &other);
        Intern& operator=(Intern &other);
        AForm *makeForm(std::string formName, std::string target);
        class InternFormException: public std::exception {
            public:
                const char* what() const throw(){
                    return ("Intern: Required FormName Not Specified");
                }
                    
            };

};

#endif