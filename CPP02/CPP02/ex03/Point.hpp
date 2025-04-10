#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
class Point{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const int x, const int y); //parameterized
        Point(Point& other);
        Point& operator=(Point &other);
        ~Point();
        bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif