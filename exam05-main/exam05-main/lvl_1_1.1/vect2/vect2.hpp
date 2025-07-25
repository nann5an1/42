#ifndef VECT_HPP
#define VECT_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>

class vect2{
    private:
        std::vector<int> _container;
    public:
        vect2();
        ~vect2();
        vect2(int v1, int v2);
        vect2(const vect2& other);
        // vect2& operator=(const vect2 &other);

        //'+' operator overloads
        vect2 operator+(int addon);
        vect2 operator+(const vect2 &other) const;
        vect2 operator++(void); //pre-increment
        vect2 operator++(int); //post-increment

        //'-' operator overloads
        vect2 operator-(int addon);
        vect2 operator-(const vect2 &other) const;
        vect2 operator--(void); //pre-increment
        vect2 operator--(int); //post-increment

        //'*' operator overload
        vect2 operator*(int multi) const;
        vect2 operator*(const vect2 &other);

        //equal assignment operator
        bool operator==(const vect2& other);
        bool operator!=(const vect2& other);
        vect2 &operator=(const vect2 &other);

        // +=, -=, *= operators
        vect2 operator+=(int add);
        vect2 operator+=(const vect2 &addon);

        vect2 operator-=(int add);
        vect2 operator-=(const vect2 &addon);

        vect2 operator*=(int add);
        vect2 operator*=(const vect2 &addon);
        int getElements(int array)const;
};

vect2 operator*(int num, const vect2 &other);
std::ostream& operator<<(std::ostream &out, const vect2 &other);

#endif