/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:05:06 by nsan              #+#    #+#             */
/*   Updated: 2025/04/10 18:06:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed(){}
Fixed::Fixed(): _fixedPointValue(0), _fractionalBits(8){}

Fixed::Fixed(const Fixed& other): _fixedPointValue(other._fixedPointValue), _fractionalBits(other._fractionalBits){
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other){
    if(this != &other)
        this->_fixedPointValue = other._fixedPointValue;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed& other){
    out << std::setprecision(6) << other.toFloat();
    return out;
} 

Fixed::Fixed(const int int_val):_fractionalBits(8){
    this->_fixedPointValue = int_val * (1 << _fractionalBits);
}

Fixed::Fixed(const float float_val):_fractionalBits(8){
    this->_fixedPointValue = roundf(float_val * (1 << _fractionalBits));
}

int Fixed::toInt(void) const{
    return roundf(this->toFloat());
}

float Fixed::toFloat(void) const{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

//assignment operator overload for 6 comparision operators
Fixed &Fixed::operator>(Fixed& other){
    return (this->_fixedPointValue > other._fixedPointValue ? *this : other);
}

Fixed &Fixed::operator<(Fixed& other){
    return (this->_fixedPointValue < other._fixedPointValue ? *this : other);
}

Fixed &Fixed::operator>=(Fixed& other){
    return (this->_fixedPointValue >= other._fixedPointValue ? *this : other);
}

Fixed &Fixed::operator<=(Fixed& other){
    return (this->_fixedPointValue <= other._fixedPointValue ? *this : other);
}

Fixed &Fixed::operator==(Fixed& other){
    return (other);
}

Fixed &Fixed::operator!=(Fixed& other){
    return (this->_fixedPointValue != other._fixedPointValue ? *this : other);
}

//operator overload for 4 arithmetic operators
Fixed Fixed::operator+(const Fixed& other)const{
    Fixed temp = *this;
    temp._fixedPointValue += other._fixedPointValue;
    return (temp);
}

Fixed Fixed::operator-(const Fixed& other)const{
    Fixed temp = *this;
    temp._fixedPointValue -= other._fixedPointValue;;
    return (temp);
}

Fixed Fixed::operator*(const Fixed& other)const{
    Fixed temp = *this;
    temp._fixedPointValue *= other.toFloat();
    return (temp);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed temp = *this;
    temp._fixedPointValue /= other._fixedPointValue;
    return (temp);
}

 //operator overload for 4 increment/decrement operators
Fixed& Fixed::operator++(){
    ++this->_fixedPointValue;
    return (*this);
}
 
Fixed Fixed::operator++(int){
    Fixed temp;
    temp._fixedPointValue = this->_fixedPointValue;
    this->_fixedPointValue++;
    return (temp);
}

Fixed& Fixed::operator--(){
    --this->_fixedPointValue;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->_fixedPointValue--;
    return (temp);
}

//static member functions
Fixed& Fixed::min(Fixed& fixed_pt1, Fixed& fixed_pt2){
    return (fixed_pt1 < fixed_pt2);
}

const Fixed& Fixed::min(const Fixed& fixed_pt1, const Fixed& fixed_pt2){
    return (fixed_pt1._fixedPointValue < fixed_pt2._fixedPointValue ? fixed_pt1 : fixed_pt2);
}

Fixed& Fixed::max(Fixed& fixed_pt1, Fixed& fixed_pt2){
    return (fixed_pt1 > fixed_pt2);
}

const Fixed& Fixed::max(const Fixed& fixed_pt1, const Fixed& fixed_pt2){
    return (fixed_pt1._fixedPointValue > fixed_pt2._fixedPointValue ? fixed_pt1 : fixed_pt2);
}


 