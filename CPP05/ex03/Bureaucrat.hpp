#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include <typeinfo>
#include "AForm.hpp"

class AForm;
class Bureaucrat{
    private:
        std::string const name;
        int grade; //highest - 1, lowest - 150
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);

        void incrementGrade(int grade);
        void decrementGrade(int grade);
        std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void signForm(AForm *form); 
        void handleExceptions();
        void executeForm(AForm* form) const;
        class GradeTooHighException: public std::exception {
        public:
            const char* what() const throw(){
                return ("Bureaucrat Grade too high");
            }
                
        };
        class GradeTooLowException: public std::exception {
        public:
            const char* what() const throw(){
                return "Bureaucrat Grade too Low";
            }
                
        };
};
    std::ostream& operator<<(std::ostream &out, Bureaucrat &b);

#endif