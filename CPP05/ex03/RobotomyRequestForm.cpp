#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm():AForm(){
   std::cout << "Robotomy Def Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
   std::cout << "Robotomy Destructor" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm(target, 72, 45){
   std::cout << "Robotomy Parameterized Constructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
:AForm(other.getFormName(), other.getGradeReqToSign(), other.getGradeReqToExecute()){
   std::cout << "Robotomy Copy Constructor." << std::endl;
   *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
   if(this != &other)
      AForm::operator=(other);
   return (*this);  
}


//have to overwrite that of AForm and test on its own conditions
void RobotomyRequestForm::beSigned(Bureaucrat *person){
    this->handleExceptions();
   if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
   {
      std::cout << person->getName() << " signed Robotomy Form " << this->getFormName() << std::endl;
      this->setIsFormSigned();
   }
   else{
      std::cout << person->getName() << " couldn’t sign Robotomy " << this->getFormName() << " because Bureaucrat rank too low." << std::endl;
      throw SignException();
   }
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
   if(executor.getGrade() <= this->getGradeReqToExecute()){
      if(rand() % 2 == 0){
         std::cout << "Makes some drilling noises " << this->getFormName() << " has been robotomized successfully 50% of the time"<< std::endl;
         std::cout << executor.getName() << " executed Robotomy " << this->getFormName() << std::endl;
      }
      else
         std::cout << "The robotomy failed." << std::endl;
   }
   else
      throw ExecutionException();
}