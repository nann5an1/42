#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm(){
   std::cout << "Shrubbery Def Constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
   std::cout << "Shrubbery Destructor" << std::endl;
};



PresidentialPardonForm::PresidentialPardonForm(ShrubberyCreationForm const &other){
   *this = other;
}

// ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
//    if (this != &other)
      
// }

 PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(formName, 145, 137){
    std::cout << target << "_shrubbery created in the working directory." << std::endl;
 }

//have to overwrite that of AForm and test on its own conditions
void PresidentialPardonForm::beSigned(Bureaucrat *person){
    this->handleExceptions(person);
     if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
    {
        std::cout << person->getName() << " signed " << this->getFormName() << std::endl;
        this->setIsFormSigned();
    }
    else
        std::cout << person->getName() << " couldn’t sign Presidential Form" << this->getFormName() << " because Bureaucrat rank too low." << std::endl;
}