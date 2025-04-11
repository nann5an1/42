#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
class Point{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const int x, const int y); //parameterized
        Point(Point& other);
        Point& operator=(Point &other);
        ~Point();
        bool bsp( Point const a, Point const b, Point const c, Point const point);
        Fixed sign(Point const &point, Point const &x, Point const &y);
};


#endif