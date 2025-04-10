#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

class Fixed{
    private:
        int _fixedPointValue;
        const int _fractionalBits;
        int _int_val;
        float _float_val;
    public:
        //constructors
        Fixed();
        Fixed(const int int_val);
        Fixed(const float float_val);
        Fixed(const Fixed& other); //copy constructor

        //copy assignment operator overload
        Fixed& operator=(const Fixed& other); 

        //assignment operator overload for 6 comparision operators
        Fixed& operator>(Fixed& other);
        Fixed& operator<(Fixed& other);
        Fixed& operator>=(Fixed& other);
        Fixed& operator<=(Fixed& other);
        Fixed& operator==(Fixed& other);
        Fixed& operator!=(Fixed& other);

        //assignment operator overload for 4 arithmetic operators
        Fixed operator+(const Fixed& other)const;
        Fixed operator-(const Fixed& other)const;
        Fixed operator*(const Fixed& other)const;
        Fixed operator/(const Fixed& other)const ;

         //assignment operator overload for 4 increment/decrement operators
        Fixed& operator++();
        Fixed operator++(int); //post-increment
        Fixed& operator--();
        Fixed operator--(int); //post-decrement

        //destructor
        ~Fixed();

        //member functions
        int toInt( void ) const;
        float toFloat( void ) const;
        static Fixed& min(Fixed& fixed_pt1, Fixed& fixed_pt2);
        const static Fixed& min(const Fixed& fixed_pt1,const Fixed& fixed_pt2);
        static Fixed& max(Fixed& fixed_pt1, Fixed& fixed_pt2);
        const static Fixed& max(const Fixed& fixed_pt1,const Fixed& fixed_pt2);
    };
    std::ostream& operator<<(std::ostream &out, const Fixed& other);

#endif