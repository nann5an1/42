#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm(){
   std::cout << "Presidential Def Constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
   std::cout << "Presidential Destructor" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : AForm(other.getFormName(), other.getGradeReqToSign(), other.getGradeReqToExecute())
{
   std::cout << "Presidential Copy Constructor." << std::endl;
   *this = other;
}


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
   if(this != &other)
      AForm::operator=(other);
   return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5){
   std::cout << "Presidential Parameterized Constructor" << std::endl;
}

//have to overwrite that of AForm and test on its own conditions
void PresidentialPardonForm::beSigned(Bureaucrat *person){
   this->handleExceptions();
   if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
   {
      std::cout << person->getName() << " signed " << this->getFormName() << std::endl;
      this->setIsFormSigned();
   }
   else{
      std::cout << person->getName() << " couldn’t sign Presidential Form" << this->getFormName() << " because Bureaucrat rank too low." << std::endl;
      throw SignException();
   }
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
   if(executor.getGrade() <= this->getGradeReqToExecute()){
      std::cout << this->getFormName() << " has been pardoned by Zaphod Beeblebrox.\n"
               << executor.getName() << " executed Presidential " << this->getFormName() << std::endl;
   }
   else
      throw ExecutionException();
}