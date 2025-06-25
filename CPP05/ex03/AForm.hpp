#ifndef AFORM_HPP
#define AFORM_HPP
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm{
    private:
        std::string const _formName;
        std::string const _target;
        std::string target; //just added the target
        bool _signedStatus;
        int const _gradeReqToSign;
        int const _gradeReqToExecute;
    public:
        AForm();
        AForm(std::string formName);
        AForm(std::string formName, int gradeReqToSign, int gradeReqToExec); //this func just to test for form-out-of-bounds
        virtual ~AForm();
        AForm(AForm const &other);
        AForm& operator=(AForm const &other);

        std::string getFormName() const;
        bool getIsFormSigned();
        void setIsFormSigned();
        int  getGradeReqToSign() const;
        int getGradeReqToExecute() const;
        virtual void beSigned(Bureaucrat *person) = 0;
        void handleExceptions();
        virtual void execute(Bureaucrat const & executor) const = 0;
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
            class ExecutionException: public std::exception{
            public:
                const char* what() const throw(){
                    return  "Bureacrat cannot execute due to low rank.";
                }
            };
            class SignException: public std::exception{
            public:
                const char* what() const throw(){
                    return  "Bureacrat cannot sign due to low rank.";
                }
            };

};
    std::ostream& operator<<(std::ostream &out, AForm &form);
#endif