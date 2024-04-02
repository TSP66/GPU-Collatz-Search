#ifndef search_h
#define search_h

#include "bigNumber.h"

class search{

    public:

    bigNumber start;
    bigNumber num;

    search(bigNumber start_point){
        num = start_point;
        start = start_point;
    }

    long startToOne(void){
        long steps = 0;
        while(!num.equal_to_one()){
            steps++;
            if(num.odd()){
                num.three_nPlusOne();
            }
            else{
                num.divideTwo();
            }
        //num.display_number();
        }
        return steps;
    }
};

#endif