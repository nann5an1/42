/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsan <nsan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:05:06 by nsan              #+#    #+#             */
/*   Updated: 2025/04/09 16:00:05 by nsan             ###   ########.fr       */
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
    *this = other; //when this is applied, in other hand also called out the copy assignment operator overload func:
}

Fixed &Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other) //check to see if the object is assigning to the same object like (b = b)
        this->_fixedPointValue = other.getRawBits();
    return (*this); //return the reference of the result
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPointValue);
}

void Fixed::setRawBits( int const raw ){
    _fixedPointValue = raw;
}