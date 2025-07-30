#include "Serializer.hpp"

int main(){
    Data mydata;
    Data *mynewdata;
  
    uintptr_t ret_ptr = Serializer::serialize(&mydata);
    mynewdata  = Serializer::deserialize(ret_ptr);

    mydata.id = 42;
    mydata.str = "Hello, World!";
    std::cout << "Data ID: " << mydata.id << std::endl;
    std::cout << "Data String: " << mydata.str << std::endl;
    std::cout << "Original pointer: " << &mydata << std::endl;
    std::cout << "New pointer: " << mynewdata << std::endl;
    
}