#ifndef bigNumber_h
#define bigNumber_h

#include <cmath>
#include <iostream>
#include <string>

typedef unsigned long long int val;

const int maxLength = 10010;
const int lengthNum = 18; //val can hold up to 19 digit numbers, but if it is set to 18, 
//it means it can be used for calcuations that briefly require more digits such as 3n+1
const val maxNum = pow(10,lengthNum);//pow(10,18);


class bigNumber{
    public:

    val data[maxLength] = { };
    
    void addition(unsigned long value);
    bool odd(void);

    void three_nPlusOne(void);

    void divideTwo(void);
    void display_number(void);
    bool equal_to_one(void);
    void display_number(val * Data);

    std::string number_to_string(void);
    std::string number_to_string(val * Data);

};

#endif