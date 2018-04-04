#include <iostream>
#include "IntegerToRoman.h"
#include <algorithm>
#include <iterator>


int main()
{
    int num;
    std::cout<<"Number:";
    std::cin>>num;
    IntegerToRoman obj23(num);
    std::cout<<obj23.MakeRomanNumber();


    return 0;
}