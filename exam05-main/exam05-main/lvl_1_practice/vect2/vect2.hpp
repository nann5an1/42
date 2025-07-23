#ifndef VECT_HPP
#define VECT_HPP

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>

class vect2{
    private:
        std::vector<int> _container;
    public:
        vect2();//default constructor, add ": _container()"
		vect2(int v1, int v2);//initalise constructor
		vect2(const vect2& original);//copy constructor
		~vect2();//	Destructor

        //'+' operator overloads
        vect2 operator++(void); //pre-increment
        vect2 operator++(int); //[post-increment
        vect2 operator+(int addon) const;
        vect2 operator+(const vect2 &other);

        //  //'-' operator overloads
        vect2 operator--(void); //pre-decrement
        vect2 operator--(int); //[post-decrement
        vect2 operator-(int addon) const;
        vect2 operator-(const vect2 &other);

        //  //'-' operator overloads
         vect2 operator*(int multi) const;
         vect2 operator*(const vect2 &other);

        //  //equal assingment operator
         vect2& operator=(const vect2 &other);
         bool operator!=(const vect2 &other);
         bool operator==(const vect2 &other);
        
        // // +=
		vect2   operator+=(int add);
		vect2   operator+=(const vect2 &addon);
		// // -=
		vect2   operator-=(int add);
		vect2   operator-=(const vect2 &addon);
		// // *=
		vect2   operator*=(int multi);
		vect2   operator*=(const vect2 &multion);
        int getContainerElements(int array) const;
};

vect2 operator*(int number, const vect2 &other);
std::ostream& operator<<(std::ostream &out, const vect2 &other);

#endif