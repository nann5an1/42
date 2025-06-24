#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():AForm(){
   std::cout << "Shrubbery Def Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
   std::cout << "Shrubbery Destructor" << std::endl;
};

// ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other){
//    *this = other;
// }

// ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
//    if (this != &other)
      
// }

 ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137){
   std::string filename = target.append("_shrubbery.txt");
   std::ofstream outfile(filename.c_str());
   if(outfile.is_open())
   {
      for(int i = 0; i < 3; i++){
         outfile << "      ###\n"
                  <<"     #o###\n"
                  <<"   #####o###\n"
                  <<"  #o#\\#|#/###\n"
                  <<"   ###\\|/#o#\n"
                  <<"    # ||| #\n"
                  <<"      ||| \n"
                  << std::endl;
      }
      outfile.close();
   }
   else
      std::cout << "File cannot be opened" << std::endl;
   std::cout << target << "_shrubbery created in the working directory." << std::endl;
 }

//have to overwrite that of AForm and test on its own conditions
void ShrubberyCreationForm::beSigned(Bureaucrat *person){
    this->handleExceptions(person);
     if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
    {
        std::cout << person->getName() << " signed " << this->getFormName() << std::endl;
        this->setIsFormSigned();
    }
    else
        std::cout << person->getName() << " couldn’t sign Shrubbery " << this->getFormName() << " because Bureaucrat rank too low." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor){
   if(executor.getGrade() <= this->getGradeReqToExecute)
      
}