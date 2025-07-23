#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <ostream>
#include <sstream> //for the exam
#include <string>

class bigint{
    private:
        std::string _string;
    public:
        bigint();
        bigint(unsigned int n); //parameterized constructor
        ~bigint();
        bigint(const bigint &other);
        bigint& operator=(const bigint &other);

        //getter value method
        std::string getValue() const;

        //increments
        bigint operator+(const bigint &other) const;
        bigint operator+=(const bigint &other);
        bigint operator++(void); //pre-increment
        bigint operator++(int); //post-increment

        //bit shifting
        bigint operator<<(unsigned int value) const;
        bigint operator<<=(unsigned int value);
        bigint operator>>=(const bigint &other);

        //boolean overloads
        bool operator>(const bigint &other);
        bool operator<(const bigint &other);
        bool operator==(const bigint &other);
        bool operator!=(const bigint &other);
        bool operator<=(const bigint &other);
        bool operator>=(const bigint &other);
};
std::ostream &operator<<(std::ostream &out ,const bigint &other);

#endif