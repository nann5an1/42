#include "vect2.hpp"

int main(void){
    vect2 a;
    vect2 b(1, 2);
    vect2 c(5, 6);
    vect2 d(c);
    vect2 e = b;
    vect2 f(4, 6);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << "++b = " << (++b) << std::endl;
    std::cout << "b++ = " << (b++) << std::endl;
    std::cout << "--d = " << (--d) << std::endl;
    std::cout << "d-- = " << (d--) << std::endl;

    std::cout << "d + b = " << (d + b) << std::endl;
    std::cout << "d - b - c = " << (d - b - c) << std::endl;

    std::cout << "d * 3 = " << (d * 3) << std::endl;
    std::cout << "d * b = " << (d * b) << std::endl;

    std::cout << "b += e = " << (b += e) << std::endl;
    std::cout << "b : " << b  << std::endl;
    std::cout << "e : " << e  << std::endl;
    std::cout << "e -= b = " << (e -= b) << std::endl;

    std::cout << "10 * b = " << (10 * b) << std::endl;

    std::cout << "b != f = " << (b != f) << std::endl; //false
    std::cout << "b == f = " << (b == f) << std::endl; //true
}