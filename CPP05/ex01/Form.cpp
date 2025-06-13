#include "Form.hpp"

//need to initialized the attributes for the constructors
Form::Form(): _formName("Dummy"), _signedStatus(false), 
_gradeReqToSign(2), _gradeReqToExecute(2){
    std::cout << "Form Default Constructor" << std::endl;
}

//modify the grade required to sign and execute here
Form::Form(std::string formName): _formName(formName), _signedStatus(false), 
_gradeReqToSign(2), _gradeReqToExecute(1){
    (void)formName;
     std::cout   << "Form Parameterized Constructor" << std::endl;
}

//modify the grade required to sign and execute here
Form::Form(std::string formName, int dummy_num): _formName("Out-Of-Bounds-Form"), _signedStatus(false), 
_gradeReqToSign(-2), _gradeReqToExecute(2){
   (void)formName;
   (void)dummy_num;
}

Form::~Form(){
    std::cout << "Form destructor" << std::endl;
}

Form::Form(Form const &other): _formName("Hummy"), _signedStatus(false), 
_gradeReqToSign(2), _gradeReqToExecute(2){
    std::cout << "Form Copy Constructor" << std::endl;
    *this = other;
}

Form& Form:: operator=(Form const &other){
    if (this != &other)
        this->_signedStatus = other._signedStatus;
    return *this;
}

std::ostream& operator<<(std::ostream &out, Form &form){
    out 
        << "Form Name -> " << form.getFormName() << std::endl
        << "Grade Required to Sign -> " << form.getGradeReqToSign() << std::endl
        << "Grade Required to Execute -> " << form.getGradeReqToExecute()
        << std::endl;
    return out;
}

std::string Form::getFormName(){
    return this->_formName;
}

bool Form::getIsFormSigned(){
    return (_signedStatus ? true : false);
}

void Form::setIsFormSigned(){
    this->_signedStatus = false;
}

int Form::getGradeReqToSign(){
    return (this->_gradeReqToSign);
}

int Form::getGradeReqToExecute(){
    return (this->_gradeReqToExecute);
}

void Form::beSigned(Bureaucrat *person){
    this->handleExceptions(person);
    std::cout << *this;
    if((person->getGrade() <= this->getGradeReqToSign()) && this->getIsFormSigned()) //1 < 2 / 1 = 1
    {
        std::cout << person->getName() << " signed " << this->getFormName() << std::endl;
        this->setIsFormSigned();
    }
    else
        std::cout << person->getName() << " couldn’t sign " << this->getFormName() << " because Bureaucrat rank too low." << std::endl;

}

//check the grade whether out of bounds or not
void Form::handleExceptions(Bureaucrat *person){
    if (this->getGradeReqToSign() < 1 || this->getGradeReqToExecute() < 1){
        delete person;
        delete this;
        throw GradeTooHighException();
    } 
    else if(this->getGradeReqToSign() > 150 || this->getGradeReqToExecute() > 150){
        delete person;
        delete this;
        throw GradeTooLowException();
    }
    else
        this->_signedStatus = 1;
}


