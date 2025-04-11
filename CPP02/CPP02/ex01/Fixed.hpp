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
        Fixed();
        Fixed(const int int_val);
        Fixed(const float float_val);
        int toInt( void ) const;
        float toFloat( void ) const;
        Fixed(const Fixed& other); //copy constructor
        Fixed& operator=(const Fixed& other); //assignment operator
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    };
    std::ostream& operator<<(std::ostream &out, const Fixed& other); //ostsream is just output stream so should be just outside of class scope

#endif