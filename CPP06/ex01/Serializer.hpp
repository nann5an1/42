#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>
// #include <cstdint>

struct Data{
    int id;
    std::string str;
};

class Serializer{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
    public:
        static uintptr_t serialize(Data* ptr); //takes a pointer and converts to the unsigned int type uintptr
        static Data* deserialize(uintptr_t raw);
};

#endif