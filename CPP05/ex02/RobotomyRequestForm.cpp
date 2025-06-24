#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():AForm(){
   std::cout << "Shrubbery Def Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
   std::cout << "Shrubbery Destructor" << std::endl;
};



RobotomyRequestForm::RobotomyRequestForm(ShrubberyCreationForm const &other){
   *this = other;
}

// ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
//    if (this != &other)
      
// }

 RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(formName, 145, 137){
    std::cout << target << "_shrubbery created in the working directory." << std::endl;
 }

//have to overwrite that of AForm and test on its own conditions
void RobotomyRequestForm::beSigned(Bureaucrat *person){
    this->handleExceptions(person);
     if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
    {
        std::cout << person->getName() << " signed Robotomy Form" << this->getFormName() << std::endl;
        this->setIsFormSigned();
    }
    else
}