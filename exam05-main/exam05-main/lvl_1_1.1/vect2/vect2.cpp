#include "vect2.hpp"

vect2::vect2(){
    this->_container.push_back(0);
    this->_container.push_back(0); 
}
vect2::~vect2(){};

vect2::vect2(int v1, int v2){
    this->_container.push_back(v1);
    this->_container.push_back(v2);
}
vect2 ::vect2(const vect2& other){
    this->_container = other._container; // Copy the vector contents
}

vect2& vect2:: operator=(const vect2 &other){
    if(this != &other){
        this->_container[0] = other._container[0]; // Copy the vector contents
        this->_container[1] = other._container[1];
    }
    return *this;
}

//'+' operator overloads
vect2 vect2:: operator+(int addon){
    vect2 temp(*this);
    temp._container[0] += addon;
    temp._container[1] += addon;
    return temp;
}

vect2 vect2:: operator+(const vect2 &other) const{
    vect2 temp(*this);
   temp._container[0] += other._container[0];
   temp._container[1] += other._container[1];
   return temp;
}

//pre-increment
vect2 vect2:: operator++(void){
    this->_container[0] += 1;
    this->_container[1] += 1;
    return *this;
}

//post-increment
vect2 vect2:: operator++(int){
    vect2 temp(*this);
    this->_container[0] += 1;
    this->_container[1] += 1;
    return temp;
}

//'-' operator overloads
vect2 vect2:: operator-(int addon){
    vect2 temp(*this);
    temp._container[0] -= addon;
    temp._container[1] -= addon;
    return temp;
}

vect2 vect2:: operator-(const vect2 &other) const{
     vect2 temp(*this);
    temp._container[0] -= other._container[0];
    temp._container[1] -= other._container[1];
    return temp;
}

vect2 vect2:: operator--(void) //pre-decrement
{
    // vect2 temp(*this);
    this->_container[0] -= 1;
    this->_container[1] -= 1;
    return *this;
}

vect2 vect2::operator--(int) //post-decrement
{
    vect2 temp(*this);
    this->_container[0] -= 1;
    this->_container[1] -= 1;
    return temp;
}

//'*' operator overload
vect2 vect2::operator*(int multi) const{
    vect2 temp(*this);
    temp._container[0] *= multi;
    temp._container[1] *= multi;
    return temp;
}

vect2 vect2::operator*(const vect2 &other){
    vect2 temp(*this);
    temp._container[0] *= other._container[0];
    temp._container[1] *= other._container[1];
    return temp;
}

//equal assignment operator
bool vect2::operator==(const vect2& other){
    if (this->_container[0] == other._container[0] && this->_container[1] == other._container[1])
        return true;
    return false;
}

bool vect2::operator!=(const vect2& other){
    if (this->_container[0] != other._container[0] || this->_container[1] != other._container[1])
        return true;
    return false;
}

// +=, -=, *= operators
vect2 vect2:: operator+=(int add){
    this->_container[0] += add;
    this->_container[1] += add;
    return (*this);
}

vect2 vect2:: operator+=(const vect2 &addon){
    this->_container[0] += addon._container[0];
    this->_container[1] += addon._container[1];
    return (*this);
}

vect2 vect2:: operator-=(int add){
    this->_container[0] -= add;
    this->_container[1] -= add;
    return (*this);
}

vect2 vect2:: operator-=(const vect2 &addon){
    this->_container[0] -= addon._container[0];
    this->_container[1] -= addon._container[1];
    return (*this);
}

vect2 vect2:: operator*=(int add){
    this->_container[0] *= add;
    this->_container[1] *= add;
    return (*this);
}

vect2 vect2:: operator*=(const vect2 &addon){
    this->_container[0] *= addon._container[0];
    this->_container[1] *= addon._container[1];
    return (*this);
}


vect2 operator*(int num, const vect2 &other){
    return (other * num);
}

int vect2::getElements(int element) const {
  return this->_container[element];
}

std::ostream& operator<<(std::ostream &out, const vect2 &other){
    out << "(" << other.getElements(0) << "," << other.getElements(1) << ")" << std::endl;
    return out;
}
