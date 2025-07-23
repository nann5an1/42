#include "bigint.hpp"

int main(){
    bigint a(42);
    bigint b(52);
    bigint c;
    bigint copy(a);
    bigint d(92);
    bigint e(1337);
    bigint copy2 = d;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << copy << std::endl; //42
    std::cout << copy2 << std::endl; //92

    std::cout << "a + b = " << a + b << std::endl; //94
    std::cout << "++b  = " << ++b << std::endl; //52
    std::cout << "b++ = " << b++ << std::endl; //54

    std::cout << "a += copy = " << (a+=copy) << std::endl; //84, a = 84
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "(a > b) = " << (a > b) << std::endl; //true
    std::cout << "(a < b) = " << (a < b) << std::endl; //false
    std::cout << "(b < a) = " << (b < a) << std::endl; //true
    std::cout << "(a == b) = " << (a == b) << std::endl; //false
    std::cout << "(a != b) = " << (a != b) << std::endl; //true
    std::cout << "(a >= b) = " << (a >= b) << std::endl; //true
    std::cout << "(a <= b) = " << (a <= b) << std::endl; //false

    std::cout << "(e << 10) + 42 = " << ((e << 10) + 42) << std::endl;
    std::cout << "(e << 3) = " << (e << 3) << std::endl;
    std::cout << "(e <<= 4) = " << (e <<= 4) << std::endl;
    std::cout << "(e >>= 3) = " << (e >>= 3) << std::endl;

}