#include "vect2.hpp"


vect2::vect2(){
    this->_container.push_back(0);
    this->_container.push_back(0);
}

vect2::vect2(int v1, int v2){
    this->_container.push_back(v1);
    this->_container.push_back(v2);
}

vect2::vect2(const vect2& other){ //copy constructor
    this->_container = other._container; //aldy using vector and hence no need to use the new keyword
}

vect2::~vect2(){}

//'+' operator overloads
vect2 vect2::operator++(void) //pre-increment
{
    vect2 temp(*this);
    this->_container[0] += 1;
    this->_container[1] += 1;
    return temp;
}

vect2 vect2:: operator++(int){ //post-increment
    this->_container[0] += 1;
    this->_container[1] += 1;
    return (*this);
}
vect2 vect2:: operator+(int addon) const{
    vect2 temp(*this);
    temp._container[0] += addon;
    temp._container[1] += addon;
    return (temp);
}
vect2 vect2:: operator+(const vect2 &other){
    vect2 temp(*this);

    temp._container[0] += other._container[0];
    temp._container[1] += other._container[1];
    return (temp);
}

//     //'-' operator overloads
vect2 vect2:: operator--(void){ //pre-decrement
    vect2 temp(*this);
    this->_container[0] -= 1;
    this->_container[1] -= 1;
    return (temp);
}

vect2 vect2:: operator--(int){  //post-decrement
    this->_container[0] -= 1;
    this->_container[1] -= 1;
    return (*this);
}

vect2 vect2:: operator-(int addon) const{
    vect2 temp(*this);

    temp._container[0] -= addon;
    temp._container[1] -= addon;
    return (temp);
}
vect2 vect2:: operator-(const vect2 &other){
    vect2 temp(*this);

    temp._container[0] -= other._container[0];
    temp._container[1] -= other._container[1];
    return (temp);
}

//     //'-' operator overloads
vect2 vect2:: operator*(int multi) const{ 
    vect2 temp(*this);

    temp._container[0] *= multi;  
    temp._container[1] *= multi;  
    return (temp);
}

vect2 vect2:: operator*(const vect2 &other){
     vect2 temp(*this);

    temp._container[0] *= other._container[0];  
    temp._container[1] *= other._container[1];  
    return (temp);
}

//     //equal assingment operator
vect2& vect2:: operator=(const vect2 &other){
    this->_container[0] = other._container[0];
    this->_container[1] = other._container[1];
    return (*this);
}
bool vect2:: operator!=(const vect2 &other){
    if (this->_container[0] != other._container[0] && this->_container[1] != other._container[1])
        return true;
    return false;
}
bool vect2:: operator==(const vect2 &other){
     if (this->_container[0] == other._container[0] && this->_container[1] == other._container[1])
        return true;
    return false;
}

// // +=
vect2 vect2::   operator+=(int add){
    this->_container[0] += add;
    this->_container[1] += add;
    return (*this);
}

vect2 vect2::   operator+=(const vect2 &addon){
    this->_container[0] += addon._container[0];
    this->_container[1] += addon._container[1];
    return (*this);
}
// // -=

vect2 vect2::   operator-=(int add){
    this->_container[0] -= add;
    this->_container[1] -= add;
    return (*this);
}

vect2 vect2::   operator-=(const vect2 &addon){
    this->_container[0] -= addon._container[0];
    this->_container[1] -= addon._container[1];
    return (*this);
}
// // *=
vect2 vect2::   operator*=(int multi){
    // vect2 temp(*this);

    this->_container[0] *= multi;
    this->_container[1] *= multi;
    return (*this);
}

vect2 vect2::   operator*=(const vect2 &multion){
    this->_container[0] *= multion._container[0];
    this->_container[1] *= multion._container[1];
    return *this;
}


int vect2::getContainerElements(int array) const{
    return this->_container[array];
}


//out of class

vect2 operator*(int number, const vect2 &other){
    return (other * number);
}



std::ostream& operator<<(std::ostream &out, const vect2 &other){
    out << "{" << other.getContainerElements(0) << "," << other.getContainerElements(1) << "}";
    return (out);
}
