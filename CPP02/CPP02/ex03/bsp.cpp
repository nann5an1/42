#include "Point.hpp"
#include "Fixed.hpp"

Fixed Point::sign(Point const &p1, Point const &p2, Point const &p3){
    return (p1._x - p3._x) * (p2._y - p3._y) - (p2._x - p3._x) * (p1._y - p3._y);
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed d1, d2, d3;
    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

    bool has_neg = d1 < Fixed(0) || d2 < Fixed(0) || d3 < Fixed(0);
    bool has_pos = d1 > Fixed(0) || d2 > Fixed(0) || d3 > Fixed(0);

    return !(has_neg && has_pos);
}