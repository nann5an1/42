/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:05:06 by nsan              #+#    #+#             */
/*   Updated: 2025/04/09 21:47:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(): _fixedPointValue(0), _fractionalBits(8){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _fixedPointValue(other._fixedPointValue), _fractionalBits(other._fractionalBits){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->_fixedPointValue = other.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed& other){ //sort of like an aliast function for <<, << is for output, not for modifying the object.
    out << std::setprecision(6) << other.toFloat(); //only affects on the float since toFloat is called
    return out;
} 

Fixed::Fixed(const int int_val):_fractionalBits(8){
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = int_val * (1 << _fractionalBits);
}

Fixed::Fixed(const float float_val):_fractionalBits(8){
    std::cout << "Float constructor called" << std::endl;
   this->_fixedPointValue = roundf(float_val * (1 << _fractionalBits));
}

int Fixed::toInt(void) const{
    return roundf(this->toFloat());
}

float Fixed::toFloat(void) const{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::getRawBits( void ) const{
    return (_fixedPointValue);
}

void Fixed::setRawBits( int const raw ){
    _fixedPointValue = raw;
}