#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

    //rank within range/ increment/ decrement
    // try
    // {
    //     std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank within range ✅\033[0m" << std::endl;
    //     Bureaucrat steve("Steve", 42); //rank within range
    //     std::cout << std::endl;

    //     std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank decrement, result --> within range ✅\033[0m" << std::endl;
    //     std::cout << "Bureaucrat name: " << steve.getName() << std::endl;
    //     std::cout << "Previous grade before increased ->" << steve.getGrade() << std::endl;
        
    //     steve.incrementGrade(41); //increase the grade/ rank --> still valid
    //     std::cout << "Current grade after increased ->" << steve.getGrade() << std::endl;
    //     std::cout << std::endl;

    //     std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank increment, result--> throw exception ✅\033[0m" << std::endl;
    //     steve.decrementGrade(150); //decrease the grade/ rank --> will throw exception
    //     std::cout << std::endl;
    // }
    // catch(const Bureaucrat::GradeTooHighException &e){ //precise exception catch
    //     std::cerr << "Particular Exception ->" << e.what() << '\n';
    // }
    // catch(const Bureaucrat::GradeTooLowException &e){
    //     std::cerr << "Particular Exception ->" << e.what() << '\n';
    // }
    // std::cout << std::endl;

    // //rank too high
    // try
    // {
    //     std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank too high, result--> throw exception ✅\033[0m" << std::endl;
    //     Bureaucrat peter("Peter", 0); //rank too high
    //     std::cout << std::endl;
    // }
    // catch(const Bureaucrat::GradeTooHighException &e){ //precise exception catch
    //     std::cerr << "Particular Exception ->" << e.what() << '\n';
    // }
    // catch(const Bureaucrat::GradeTooLowException &e){
    //     std::cerr << "Particular Exception ->" << e.what() << '\n';
    // }
    // std::cout << std::endl;


    // //rank too low
    // try
    // {
    //     std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank too low, result--> throw exception ✅\033[0m" << std::endl;
    //     Bureaucrat jack("Jack", 151); //rank too low
    //     std::cout << std::endl;
    // }
    // catch(const std::exception &e){ //general exception catch
    //     std::cerr << e.what() << '\n';
    // }
    // std::cout << std::endl;

    // //copy constructors test
    // try
    // {
    //     std::cout << "\033[1;32m[TEST CASE](Copy Constructors) Bureaucrat rank too low, result--> throw exception ✅\033[0m" << std::endl;
    //     Bureaucrat rank1("Boho", 2);
    //     Bureaucrat rank2(rank1); //rank too low
    //     std::cout << std::endl;
    // }
    // catch(const std::exception &e){ //general exception catch
    //     std::cerr << e.what() << '\n';
    // }
    // std::cout << std::endl;
    
    // //test for valid bureacrat grade with valid signing authority 
    // try
    // {
    //     Form *form;
    //     Form *form1;
    //     Bureaucrat *steve;
    //     Bureaucrat *steve1;
    //     std::cout << "\033[1;32m[TEST CASE]Valid Bureacrat grade with valid signing authority, res -> must be SIGNED ✅\033[0m" << std::endl;
    //     steve = new Bureaucrat("Steve", 1);
    //     form = new Form("Dummy Form");
    //     steve->signForm(form);

    //     std::cout << "\033[1;32m[TEST CASE]Valid Bureacrat grade with invalid signing authority, res -> must NOT be SIGNED ✅\033[0m" << std::endl;
    //     steve1 = new Bureaucrat("Steve", 10);
    //     form1 = new Form("Dummy Form");
    //     steve1->signForm(form);

    //     delete form;
    //     delete steve;
    //     delete form1;
    //     delete steve1;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    

    // //test for copies of form
    // try
    // {
    //     Form *form;
    //     Form *form1;
    //     Bureaucrat *steve;

    //     std::cout << "\033[1;32m[TEST CASE](Copy Constructors)Valid Bureacrat grade with valid signing authority, res -> must be SIGNED ✅\033[0m" << std::endl;
    //     steve = new Bureaucrat("Steve", 2);
    //     form = new Form("Dummy Form");
    //     form1 = form;
        
    //     steve->incrementGrade(1);
    //     steve->signForm(form);
    //     std::cout << std::endl;
    //     steve->signForm(form1);

    //     delete form1;
    //     delete steve;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    //  //test for copies of bureacrats
    // try
    // {
    //     Form *form;
    //     Bureaucrat *steve;
    //     Bureaucrat *steve1;

    //     std::cout << "\033[1;32m[TEST CASE](Copy Constructors)Valid Copies of Bureacrats, res -> must NOT be SIGNED ✅\033[0m" << std::endl;
    //     steve1 = new Bureaucrat("Steve1", 3);

    //     form = new Form("Dummy Form");
    //     steve = steve1;
    //     steve->signForm(form);
    
    //     delete form;
    //     delete steve;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }


    // //test for form out of bounds exception
    // try
    // {
    //     Form *form;
    //     Bureaucrat *steve;
    //     std::cout << "\033[1;32m[TEST CASE]Form Class Out Of Bounds Exception ✅\033[0m" << std::endl;
    //     steve = new Bureaucrat("Steve", 1);
    //     form = new Form("Dummy Form", -2);
    //     steve->signForm(form);

    //     delete form;
    //     delete steve;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
   //       delete form;
   //       delete steve;
    // }

   //////////////////////////////////   EX02  //////////////////////////////////////
    //test for form out of bounds execution exception -> SHRUBBERY
    Auto *shrubbery = NULL;
    AForm *robotomy = NULL;
    AForm *presidential = NULL;
    Bureaucrat *steve = NULL;
    try
    {
        //• ShrubberyCreationForm: Required grades: sign 145, exec 137
        std::cout << "\033[1;32m[TEST CASE]form out of bounds execution exception -> SHRUBBERY✅\033[0m" << std::endl;
        shrubbery = new ShrubberyCreationForm("Dummy Form");
        steve = new Bureaucrat("Steve", 137);

        steve->signForm(shrubbery);
        steve->executeForm(shrubbery);
        delete shrubbery;
        delete steve;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete shrubbery;
        delete steve;
    }

     //test for form out of bounds execution exception -> ROBOTOMY
    try
    {
        //RobotomyRequestForm: Required grades: sign 72, exec 45
        std::cout << "\033[1;32m[TEST CASE]form out of bounds execution exception -> ROBOTOMY✅\033[0m" << std::endl;
        robotomy = new RobotomyRequestForm("Robort Form");
        steve = new Bureaucrat("Steve", 71);

        steve->signForm(robotomy);
        steve->executeForm(robotomy);
        delete robotomy;
        delete steve;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete robotomy;
        delete steve;
    }

   //test for ROBOTOMY and PRESIDENTIAL
   try
   {
       //PresidentialPardonForm: Required grades: sign 25, exec 5
      std::cout << "\033[1;32m[TEST CASE]Presidential & Robotomy✅\033[0m" << std::endl;
      presidential = new PresidentialPardonForm("military form");
      robotomy = new RobotomyRequestForm("form for Tina");
      steve = new Bureaucrat("Steve", 25);

      steve->signForm(presidential);
      steve->executeForm(presidential);

      steve->signForm(robotomy);
      steve->executeForm(robotomy);
      delete presidential;
      delete robotomy;
      delete steve;
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
      delete presidential;
      delete robotomy;
      delete steve;
   }

   //test for copy constructors of the forms
   try
   {
      //PresidentialPardonForm: Required grades: sign 25, exec 5
      //RobotomyRequestForm: Required grades: sign 72, exec 45
      //ShrubberyCreationForm: Required grades: sign 145, exec 137
      std::cout << "\033[1;32m[TEST CASE]form out of bounds execution exception -> Presidential & Robotomy\033[0m" << std::endl;
      PresidentialPardonForm presidential("military form");
      RobotomyRequestForm robotomy("robot form");
      ShrubberyCreationForm shrubbery("Wix Map");

      steve = new Bureaucrat("Steve", 5);
      std::cout << "\n\033[1;32m[TEST CASE]Presidential Copy Constructor\033[0m" << std::endl;
      steve->signForm(&presidential); //signstatus = 0
      steve->executeForm(&presidential);

      //copy constructor test for presidential
      PresidentialPardonForm presidential1(presidential);
      std::cout << "Presidential1 Form Status :" << presidential1.getIsFormSigned() << "\n"
               << "Presidential1 Form Name: " <<  presidential1.getFormName() << "\n"
               << std::endl;

      //copy constructor test for robotomy
      std::cout << "\n\033[1;32m[TEST CASE]Robotomy Copy Constructor\033[0m" << std::endl;
      steve->signForm(&robotomy);
      RobotomyRequestForm robotomy1(robotomy);
      std::cout << "Robotomy1 Grade : " << robotomy1.getGradeReqToExecute() << std::endl;
      std::cout << "Robotomy1 Sign Status : " << robotomy1.getIsFormSigned() << std::endl;
      steve->executeForm(&robotomy1);

      std::cout << "\n\033[1;32m[TEST CASE]Shrubbery Copy Constructor\033[0m" << std::endl;
      //copy constructor test for shrubbery
      steve->executeForm(&shrubbery);
      steve->signForm(&shrubbery); //signstatus 1
      ShrubberyCreationForm shrubbery1(shrubbery);
      std::cout << "Shrubbery1 Req To Execute:" << shrubbery1.getGradeReqToExecute() << "\n"
               << "Shrubbery1 Form Name: " <<  shrubbery1.getFormName() << "\n"
               << "Shrubbery1 Form Status:" << shrubbery1.getIsFormSigned() << "\n"
               << std::endl;
      delete steve;
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
      delete steve;
   }
}