#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string formName);
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm& operator=(PresidentialPardonForm const &other);
        void beSigned(Bureaucrat *person);
        void execute(Bureaucrat const & executor) const;
};

#endif