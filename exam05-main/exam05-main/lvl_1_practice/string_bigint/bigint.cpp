#include "bigint.hpp"
   
bigint:: bigint(){
     _string = "0";
}
bigint::~bigint(){}

//convert from int to string
bigint::bigint(unsigned int n){
    std::ostringstream oss;
    oss << n;
    this->_string = oss.str();
} //parameterized constructor

        
bigint::bigint(const bigint &other){
   this->_string = other._string;
}


std::ostream &operator<<(std::ostream &out ,const bigint &other){
    out  << other.getValue();
    return out;
}

bigint& bigint:: operator=(const bigint &other){
    if(this != &other)
       this->_string = other._string;
    return (*this);
}

//getter value 
std::string bigint:: getValue() const{
    return this->_string;
}

//increments
bigint bigint ::operator+(const bigint &other) const{
    bigint temp(*this); //this's string will be in temp

    //first check which has the longer string
    std::string str1 = this->_string;
    std::string str2 = other._string;
    if(str2.size() > str1.size())
        std::swap(str1, str2);
    std::string result = "";
    int carry = 0;
    int i = str1.length() - 1;
    int j = str2.length() - 1;
    while (i >= 0 || j >= 0 || carry){
        int digit1 = i >= 0 ? str1[i] - '0' : 0;
        int digit2 = j >= 0 ? str2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        i--;
        j--;
        result.insert(result.begin(), (sum % 10) + '0'); //if total e.g 221 get the result in reverse
        carry = sum / 10;
    }
    temp._string = result;
    return (temp);
}

//compound add assignment
bigint bigint :: operator+=(const bigint &other){
    *this = *this + other;
    return *this;
}

//pre-increment
bigint bigint :: operator++(void){
    bigint temp(*this); //save the state of *this
    bigint temp2(1); //parameterized constructor convert int to str
    //++a

    *this += temp2; //*this = *this + temp2
    return (*this);
}

//post-increment
bigint bigint :: operator++(int){
    bigint temp1(*this);
    bigint temp(1); //parameterized constructor

    *this += temp; //*this = *this + temp
    return temp1;
}

//bit shifting
bigint bigint :: operator<<(unsigned int shift) const{
    bigint copy(*this);

    if(copy._string == "0") //safety check always first
        return copy;
    //121
    copy._string.append(shift, '0');
    return copy; //12100 if shift is 2
}

bigint bigint :: operator<<=(unsigned int shift){
    if(this->_string == "0")
        return (*this);
    this->_string.append(shift, '0');
    return (*this);
}

bigint bigint :: operator>>=(const bigint &other){
    if(this->_string == "0")
        return *this;

    std::stringstream ss;
    ss << other;
    size_t shift = 0;
    ss >> shift;

    // std::cout << "string length : " << this->_string.length() << std::endl;
    // std::cout << "shift : " << shift << std::endl;
    if(this->_string.size() > shift) //12345 > shifting "3"
        this->_string = this->_string.substr(0, this->_string.length() - shift);
    else{ //12 > shifting 2
        this->_string.clear();
        this->_string.push_back('0');
    }
    return *this;
}

//boolenan overloads
bool bigint ::operator==(const bigint &other){
    if (this->_string == other._string)
        return true;
    return false;
}

bool bigint :: operator!=(const bigint &other){
    if (this->_string != other._string)
        return true;
    return false;
}


bool bigint:: operator<(const bigint &other){
    if(this->_string.size() < other._string.size())
        return true;
    if (this->_string.size() > other._string.size())
		return (false);
    //comparison  by each digit
    std::string x1 = this->_string; //1120
    std::string x2 = other._string; //1130
   
    for(size_t i = 0; i< this->_string.size(); i++){
        if(x1[i] < x2[i])
            return true;
        else
            return false;
    }
    return false;
}

bool bigint:: operator>(const bigint &other){
    if(this->_string.size() > other._string.size())
        return true;
    if (this->_string.size() < other._string.size())
		return (false);
    std::string x1 = this->_string; //1120
    std::string x2 = other._string; //1130
   
    for(size_t i = 0; i< this->_string.size(); i++){
        if(x1[i] != x2[i]){
            if(x1[i] > x2[i])
                return true;
            else
                return false;
        }
    }
    return false;
}

bool bigint :: operator<=(const bigint &other){
    if(this->_string == other._string)
        return true;
    if(*this < other)
        return true;
    return false;
}

bool bigint :: operator>=(const bigint &other){
    if(this->_string == other._string)
        return true;
    if(*this > other) //call the operator > overload 
        return true;
    return false;
}
