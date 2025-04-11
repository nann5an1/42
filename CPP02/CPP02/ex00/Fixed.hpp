#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>

class Fixed{
    private:
        int _fixedPointValue;
        const int _fractionalBits;
    public:
        Fixed();
        Fixed(const Fixed& other); //copy constructor
        Fixed& operator=(const Fixed& other); //assignment operator
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    };  

#endif