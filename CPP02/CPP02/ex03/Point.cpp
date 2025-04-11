#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): _x(0), _y(0){}

Point::Point(const int x, const int y): _x(x), _y(y){}

Point::Point(Point& other){
    *this = other;
}

Point& Point::operator=(Point &other){
    (Fixed)this->_x = other._x;
    (Fixed)this->_y = other._y;
    return (*this);
}

Point:: ~Point(){ }