#include <iostream>
#include "Mystring.h"

int main()
{
    MyString a{ "Hello" };                  // overloaded constructor
    MyString b;                             // no-args contructor

    b = a;                                      // copy assignment 
    a = MyString{ "I wanna be moved!" };        // move assignment

    MyString eval_a{ a };
    std::cout<<"compare MyStrings "<< (eval_a == a) << std::endl;

    MyString part_one{ "I am " };
    MyString part_two{ "programmer" };
    std::cout << "concat MyStrings "<< (part_one + part_two).get_str() << std::endl;
}
