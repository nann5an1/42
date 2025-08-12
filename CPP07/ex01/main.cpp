#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    char ch_arr[] = {'a', 'b', 'c', 'd', 'e'};
    // char* str_array = {"apple", "orange", "banana"};
    iter(arr, 5, increment<int>);  // call iter with print function
    iter(ch_arr, 5, increment<char>);
    iter(arr, 5, increment<int>);
    // iter(str_array, 3, findGrape<char *>);
    return 0;
}
