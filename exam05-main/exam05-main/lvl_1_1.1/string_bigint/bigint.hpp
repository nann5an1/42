#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
// #include <algorithm>

class bigint{
    private:
        std::string _string;
    public:
        bigint();
        ~bigint();
        bigint(unsigned int val);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);

        //operator overloading
        bigint operator+(const bigint &other) const;
        bigint operator+=(const bigint &other);
        bigint operator++(int); //postfix increment
        bigint operator++(void); //prefix increment

        //comparison operators ovreloading
        bool operator>(const bigint& other);
        bool operator<(const bigint& other);
        bool operator>=(const bigint& other);
        bool operator<=(const bigint& other);
        bool operator==(const bigint& other);
        bool operator!=(const bigint& other);

        //bit shift operators overloading
        bigint operator<<(unsigned int shift)const;
        bigint operator<<=(unsigned int shift); 
        bigint operator>>=(const bigint &other);
        std::string getValue() const;
           
};

std::ostream& operator<<(std::ostream& out, const bigint& other);

#endif