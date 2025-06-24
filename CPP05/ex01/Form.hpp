#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm{
    private:
        std::string const _formName;
        bool _signedStatus;
        int const _gradeReqToSign;
        int const _gradeReqToExecute;
    public:
        AForm();
        AForm(std::string formName);
        AForm(std::string formName, int dummy_num); //this func just to test for form-out-of-bounds
        ~AForm();
        AForm(AForm const &other);
        AForm& operator=(AForm const &other);

        std::string getFormName();
        bool getIsFormSigned();
        void setIsFormSigned();
        int  getGradeReqToSign();
        int getGradeReqToExecute();
        void beSigned(Bureaucrat *person);
        void handleExceptions(Bureaucrat *person);
        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw(){
                    return ("Form::GradeTooHighException");
                }
                    
            };
            class GradeTooLowException: public std::exception {
            public:
                const char* what() const throw(){
                    return "Form::GradeTooLowException";
                }
                    
            };

};
    std::ostream& operator<<(std::ostream &out, AForm &form);
#endif