#include "bigint.hpp"

bigint::bigint(){
    _string = "0";
}
bigint::~bigint(){}

bigint::bigint(unsigned int val){
    std::stringstream ss;
    ss << val;
    this->_string = ss.str();
}

bigint::bigint(const bigint& other){
    this->_string = other._string;
}

bigint& bigint::operator=(const bigint& other){
    if(this != &other)
        this->_string = other._string;
    return *this;
}

//operator overloading
bigint bigint::operator+(const bigint &other) const{
    bigint temp(*this);
    if(this->_string == "0")
        return other;
    if(other._string == "0")
        return *this;
    std::string st1 = this->_string;
    std::string st2 = other._string;
    if(this->_string.size() < other._string.size())
        std::swap(st1, st2);
    int i = this->_string.length() - 1;
    int j = other._string.length() - 1;


    int carry = 0;
    std::string result = "";

    while(i >= 0  || j >= 0 || carry){
        int digit1 = (i >= 0) ? this->_string[i] - '0' : 0;
        int digit2 = (j >= 0) ? other._string[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        i--;
        j--;
        result.insert(result.begin(), sum % 10 + '0');
        carry = sum / 10;
    }
    temp._string = result;
    return temp;
}

bigint bigint::operator+=(const bigint &other){
    *this = *this + other;
    return *this;
}

bigint bigint::operator++(int) //postfix increment
{
    bigint temp(*this);
    bigint increment(1);
    *this += increment;
    return temp;
}
bigint bigint::operator++(void) //prefix increment
{
    bigint increment(1);
    *this += increment;
    return *this;
}

//comparison operators ovreloading
bool bigint::operator>(const bigint& other){
    if(this->_string == "0")
        return false;
    if(other._string == "0")
        return true;
    if(this->_string.size() > other._string.size())
        return true;
    if(this->_string.size() < other._string.size())
        return false;

    std::string str1 = this->_string;
    std::string str2 = other._string;
    for(size_t i = 0; i < str1.size(); i++){
        if(str1[i] > str2[i])
            return true;
        else if(str1[i] < str2[i])
            return false;
    }
    return false;
}
bool bigint::operator<(const bigint& other){
      if(this->_string == "0")
        return true;
    if(other._string == "0")
        return false;
    if(this->_string.size() > other._string.size())
        return false;
    if(this->_string.size() < other._string.size())
        return true;
        
    std::string str1 = this->_string;
    std::string str2 = other._string;
    for(size_t i = 0; i < str1.size(); i++){
        if(str1[i] < str2[i])
            return true;
        else if(str1[i] > str2[i])
            return false;
    }
    return false;
}
bool bigint::operator>=(const bigint& other){
    if (*this == other)
        return true;
    if (*this > other)
        return true;
    return false;
}
bool bigint::operator<=(const bigint& other){
   if (*this == other)
        return true;
    if (*this < other)
        return true;
    return false;
}
bool bigint::operator==(const bigint& other){
    return this->_string == other._string ? true: false;
}
bool bigint::operator!=(const bigint& other){
    return this->_string != other._string ? true: false;
}

//bit shift operators overloading
bigint bigint::operator<<(unsigned int shift)const{
    bigint temp(*this);

    if(temp._string == "0")
        return temp;
    temp._string.append(shift, '0');
    return temp;

}
bigint bigint::operator<<=(unsigned int shift){
    if(this->_string == "0")
        return *this;
    this->_string.append(shift, '0');
    return *this;
}

bigint bigint::operator>>=(const bigint &other){
    if(this->_string == "0")
        return *this;
    std::stringstream ss;
    ss << other;
    size_t shift = 0;
    ss >> shift;
    if(this->_string.size() > shift)
        this->_string = this->_string.substr(0, this->_string.length() - shift);
    else
    {
        this->_string.clear();
        this->_string.push_back('0');
    }
    return *this;
}

std::string bigint::getValue() const{
    return this->_string;
}

std::ostream& operator<<(std::ostream &out, const bigint& other){
    out << other.getValue();
    return out;
}