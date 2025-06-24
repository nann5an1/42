#include "AForm.hpp"

//need to initialized the attributes for the constructors
AForm::AForm(): _formName("Dummy"), _signedStatus(false), 
_gradeReqToSign(2), _gradeReqToExecute(2){
    std::cout << "Form Default Constructor" << std::endl;
}

//modify the grade required to sign and execute here
AForm::AForm(std::string formName): _formName(formName), _signedStatus(false), 
_gradeReqToSign(2), _gradeReqToExecute(1){
    (void)formName;
     std::cout   << "Form Parameterized Constructor" << std::endl;
}

//modify the grade required to sign and execute here
AForm::AForm(std::string formName, int gradeReqToSign, int gradeReqToExec): _formName(formName), _signedStatus(false), 
_gradeReqToSign(gradeReqToSign), _gradeReqToExecute(gradeReqToExec){
    (void)formName;
    (void)gradeReqToSign;
    (void)gradeReqToExec;
}

AForm::~AForm(){
    std::cout << "Form destructor" << std::endl;
}

AForm::AForm(AForm const &other): _formName("Hummy"), _signedStatus(false), 
_gradeReqToSign(2), _gradeReqToExecute(2){
    std::cout << "Form Copy Constructor" << std::endl;
    *this = other;
}

AForm& AForm:: operator=(AForm const &other){
    if (this != &other)
        this->_signedStatus = other._signedStatus;
    return *this;
}

std::ostream& operator<<(std::ostream &out, AForm &form){
    out 
        << "Form Name -> " << form.getFormName() << std::endl
        << "Grade Required to Sign -> " << form.getGradeReqToSign() << std::endl
        << "Grade Required to Execute -> " << form.getGradeReqToExecute()
        << std::endl;
    return out;
}

std::string AForm::getFormName(){
    return this->_formName;
}

bool AForm::getIsFormSigned(){
    return (_signedStatus ? true : false);
}

void AForm::setIsFormSigned(){
    this->_signedStatus = false;
}

int AForm::getGradeReqToSign(){
    return (this->_gradeReqToSign);
}

int AForm::getGradeReqToExecute(){
    return (this->_gradeReqToExecute);
}

void AForm::beSigned(Bureaucrat *person){
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
void AForm::handleExceptions(Bureaucrat *person){
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

void AForm::execute(Bureaucrat const & executor){
    if(executor.getGrade() <= this->_gradeReqToExecute && this->getIsFormSigned){
        std::cout << executor << "executed" << this->_formName << std::endl;
    }
    else{
        delete executor;
        throw ExecutionException();
    }
}
        