#include "Span.hpp"

int main(){
    // srand(time(0));
    //test for that span is check for overflowed
    std::cout << "\nTest for that span is check for overflowed" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    try
    {
        Span sp = Span(5); //create a span of , size 5
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;


        unsigned int array[3];
        for( int i = 0; i < 3; i++)
            array[i] = rand() % 5;
        
        std::cout << "\nSpan Test for Overflow Check before longestSpan" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        sp.addMultipleNumbers(array, array + 3);
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //test for at least 10000 numbers in the span
    std::cout << "\nSpan Test for at Least 10000 numbers" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
     try
    {
        Span sp = Span(MAX_NUM); //create a span of , size 5
        
        unsigned int array[MAX_NUM];
        for( int i = 0; i < MAX_NUM; i++)
            array[i] = rand() % MAX_NUM;
        sp.addMultipleNumbers(array, array + MAX_NUM);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //throw exception due to span not enough size
    try
    {
        Span sp = Span(2);
        sp.addNumber(6);
        std::cout << sp.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
    return 0;
}