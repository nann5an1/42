#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default Bureaucrat"), grade(1){
    std::cout << "Bureaucrat Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): name(name), grade(grade) {
    std::cout   << "Bureaucrat Parameterized Constructor\n" 
                << "Bureaucrat Name -> " << name << "\n"
                << "Bureaucrat Grade ->" << grade
                << std::endl;
    handleExceptions();
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name("Copied Bureaucrat"), grade(1){
    std::cout << "Bureaucrat Copy Constructor" << std::endl;
    *this = other;
    std::cout << *this;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b){
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n" << std::endl;
    return out;
}

void Bureaucrat::incrementGrade(int increase){
    this->grade -= increase;
    handleExceptions();
}

void Bureaucrat::decrementGrade(int decrease){
    this->grade += decrease;
    handleExceptions();
}

std::string Bureaucrat:: getName(){
    return this->name;
}

int Bureaucrat:: getGrade(){
    return this->grade;
}

void Bureaucrat::setGrade(int grade){
    this->grade = grade;
}

void Bureaucrat:: signForm(AForm *form){
    form->beSigned(this);
}

void Bureaucrat::handleExceptions(){
    if (this->grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    else
        std::cout << *this;
}