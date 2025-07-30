#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &other){
   *this = other;
}

Serializer& Serializer:: operator=(const Serializer &other){
    if(this != &other){
        (void)other;
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) //takes a pointer and converts to the unsigned int type uintptr
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}


