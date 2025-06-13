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
        Bureaucrat rank1("Boho", 3);
        Bureaucrat rank2(rank1);
        rank2.setGrade(155);
        std::cout << std::endl;
    }
    catch(const std::exception &e){ //general exception catch
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    
}