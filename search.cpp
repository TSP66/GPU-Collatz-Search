#include "search.h"

search::search(bigNumber start_point){
    num = start_point;
    start = start_point;
}

long search::startToOne(void){
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