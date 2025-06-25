#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string formName);
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm& operator=(RobotomyRequestForm const &other);
        void beSigned(Bureaucrat *person);
        void execute(Bureaucrat const & executor) const;
};

#endif