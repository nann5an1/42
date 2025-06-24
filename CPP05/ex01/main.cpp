#include "Bureaucrat.hpp"

int main(){

    //rank within range/ increment/ decrement
    try
    {
        std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank within range ✅\033[0m" << std::endl;
        Bureaucrat steve("Steve", 42); //rank within range
        std::cout << std::endl;

        std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank decrement, result --> within range ✅\033[0m" << std::endl;
        std::cout << "Bureaucrat name: " << steve.getName() << std::endl;
        std::cout << "Previous grade before increased ->" << steve.getGrade() << std::endl;
        
        steve.incrementGrade(41); //increase the grade/ rank --> still valid
        std::cout << "Current grade after increased ->" << steve.getGrade() << std::endl;
        std::cout << std::endl;

        std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank increment, result--> throw exception ✅\033[0m" << std::endl;
        steve.decrementGrade(150); //decrease the grade/ rank --> will throw exception
        std::cout << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException &e){ //precise exception catch
        std::cerr << "Particular Exception ->" << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e){
        std::cerr << "Particular Exception ->" << e.what() << '\n';
    }
    std::cout << std::endl;

    //rank too high
    try
    {
        std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank too high, result--> throw exception ✅\033[0m" << std::endl;
        Bureaucrat peter("Peter", 0); //rank too high
        std::cout << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException &e){ //precise exception catch
        std::cerr << "Particular Exception ->" << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e){
        std::cerr << "Particular Exception ->" << e.what() << '\n';
    }
    std::cout << std::endl;


    //rank too low
    try
    {
        std::cout << "\033[1;32m[TEST CASE] Bureaucrat rank too low, result--> throw exception ✅\033[0m" << std::endl;
        Bureaucrat jack("Jack", 151); //rank too low
        std::cout << std::endl;
    }
    catch(const std::exception &e){ //general exception catch
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    //copy constructors test
    try
    {
        std::cout << "\033[1;32m[TEST CASE](Copy Constructors) Bureaucrat rank too low, result--> throw exception ✅\033[0m" << std::endl;
        Bureaucrat rank1("Boho", 2);
        Bureaucrat rank2(rank1); //rank too low
        std::cout << std::endl;
    }
    catch(const std::exception &e){ //general exception catch
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
    //test for valid bureacrat grade with valid signing authority 
    try
    {
        AForm *form;
        AForm *form1;
        Bureaucrat *steve;
        Bureaucrat *steve1;
        std::cout << "\033[1;32m[TEST CASE]Valid Bureacrat grade with valid signing authority, res -> must be SIGNED ✅\033[0m" << std::endl;
        steve = new Bureaucrat("Steve", 1);
        form = new AForm("Dummy Form");
        steve->signForm(form);

        std::cout << "\033[1;32m[TEST CASE]Valid Bureacrat grade with invalid signing authority, res -> must NOT be SIGNED ✅\033[0m" << std::endl;
        steve1 = new Bureaucrat("Steve", 10);
        form1 = new AForm("Dummy Form");
        steve1->signForm(form);

        delete form;
        delete steve;
        delete form1;
        delete steve1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    //test for copies of form
    try
    {
        AForm *form;
        AForm *form1;
        Bureaucrat *steve;

        std::cout << "\033[1;32m[TEST CASE](Copy Constructors)Valid Bureacrat grade with valid signing authority, res -> must be SIGNED ✅\033[0m" << std::endl;
        steve = new Bureaucrat("Steve", 2);
        form = new AForm("Dummy Form");
        form1 = form;
        
        steve->incrementGrade(1);
        steve->signForm(form);
        std::cout << std::endl;
        steve->signForm(form1);

        delete form1;
        delete steve;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

     //test for copies of bureacrats
    try
    {
        AForm *form;
        Bureaucrat *steve;
        Bureaucrat *steve1;

        std::cout << "\033[1;32m[TEST CASE](Copy Constructors)Valid Copies of Bureacrats, res -> must NOT be SIGNED ✅\033[0m" << std::endl;
        steve1 = new Bureaucrat("Steve1", 3);

        form = new AForm("Dummy Form");
        steve = steve1;
        steve->signForm(form);
    
        delete form;
        delete steve;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    //test for form out of bounds exception
    try
    {
        AForm *form;
        Bureaucrat *steve;
        std::cout << "\033[1;32m[TEST CASE]Form Class Out Of Bounds Exception ✅\033[0m" << std::endl;
        steve = new Bureaucrat("Steve", 1);
        form = new AForm("Dummy Form", -2);
        steve->signForm(form);

        delete form;
        delete steve;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}