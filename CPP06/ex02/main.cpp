#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"    
#include "C.hpp"

Base* generate(void){
    srand(time(0));
    int random = rand() % 3;
    
    switch (random){
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
};

void identify(Base* p){ //if upcasting fails using pointer, return will be NULL
    if(dynamic_cast<A *>(p))
        std::cout << "Type: A" << std::endl;
    else if(dynamic_cast<B *>(p))
        std::cout << "Type: B" << std::endl;
    else if(dynamic_cast<C *>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Type: Default Base" << std::endl;
    return ;
}

void identify(Base& p){
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "Ref Type: A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: Type A " << e.what() << '\n';
    }
    try
    {
        dynamic_cast<B &>(p);
        std::cout << "Ref Type: B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: Type B " << e.what() << '\n';
    }
    try
    {
        dynamic_cast<C &>(p);
        std::cout << "Ref Type: C" << std::endl;
        return ;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: Type C " << e.what() << '\n';
    }
}



int main(){
    std::cout << "\033[1;32mRandom generated objects\033[0m" << std::endl;
    Base *base = generate();
    identify(base); //parse as a pointer
    identify(*base); //parse as a reference
    std::cout << "" << std::endl;

    A *a = new A();
    B *b = new B();    
    C *c = new C();
    std::cout << "\033[1;32mClass A\033[0m" << std::endl;
    identify(a); //parse as a pointer
    identify(*a); //parse as a reference
    std::cout << "" << std::endl;

    std::cout << "\033[1;32mClass B\033[0m" << std::endl;
    identify(b); //parse as a pointer
    identify(*b); //parse as a reference
    std::cout << "" << std::endl;

    std::cout << "\033[1;32mClass C\033[0m" << std::endl;
    identify(c); //parse as a pointer
    identify(*c); //parse as a reference

    delete base;
    delete a;
    delete b;
    delete c;
    return 0;
}