#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():AForm(){
   std::cout << "Shrubbery Def Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
   std::cout << "Shrubbery Destructor" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
:AForm(other.getFormName(), other.getGradeReqToSign(), other.getGradeReqToExecute())
{
   std::cout << "Shrubbery Copy Constructor" << std::endl;
   *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
   if(this != &other)
      AForm::operator=(other);
   return (*this); 
}

 ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137){
  std::cout << "Shrubbery Parameterized Constructor" << std::endl;
 }

//have to overwrite that of AForm and test on its own conditions
void ShrubberyCreationForm::beSigned(Bureaucrat *person){
   this->handleExceptions();
   if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
   {
      std::cout << person->getName() << " signed Shrubbery Form " << this->getFormName() << std::endl;
      this->setIsFormSigned();
   }
   else{
      std::cout << person->getName() << " couldn’t sign Shrubbery " << this->getFormName() << " because Bureaucrat rank too low." << std::endl;
      throw SignException();
   }
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
   if(executor.getGrade() <= this->getGradeReqToExecute()){
      std::cout << executor.getName() << " executed Shrubbery " << this->getFormName() << std::endl;
      std::string filename = this->getFormName().append("_shrubbery.txt");
      std::ofstream outfile(filename.c_str(), std::ios::app);
      if(outfile.is_open())
      {
         outfile << "      ###\n"
                  <<"     #o###\n"
                  <<"   #####o###\n"
                  <<"  #o#\\#|#/###\n"
                  <<"   ###\\|/#o#\n"
                  <<"    # ||| #\n"
                  <<"      ||| \n"
                  << std::endl;
         outfile.close();
      }
      else
         std::cout << "File cannot be opened" << std::endl;
      std::cout << this->getFormName() << "_shrubbery created in the working directory." << std::endl;
   }
   else
      throw ExecutionException();
}