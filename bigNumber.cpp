#include "bigNumber.h"

//val bigNumber::data[maxLength] = { };
    
void bigNumber::addition(unsigned long value){ //Not for negative numbers

    bool notFinished = true;
    int pos = 0;
    long append_value = value;

    while(notFinished){
        val sum = data[pos] + append_value;
        if(value >= maxNum){
            bigNumber::data[pos] = sum - maxNum;
            append_value = 1; // Only possible to carry one over
            pos++;
        }
        else{
            bigNumber::data[pos] = sum;
            notFinished = false;
            break;
        }
    }
}

bool bigNumber::odd(void){
    if(bigNumber::data[0] % 2 == 1) return 1;
    return 0;
}

void bigNumber::three_nPlusOne(void){
    for(int i = maxLength-1; i >= 0; i--){
        if((i == maxLength-1) && (data[i] > maxNum/3)) throw "Not possible - need more length";
        if(bigNumber::data[i] < maxNum/3){
            bigNumber::data[i] = 3*bigNumber::data[i];
        }
        else{
            bigNumber::data[i+1] = bigNumber::data[i+1] + floor((3*bigNumber::data[i])/maxNum);
            bigNumber::data[i] = (3*bigNumber::data[i]) % maxNum;
        }
    }
    bigNumber::addition(1);
}

void bigNumber::divideTwo(void){
    if(bigNumber::odd() == 1) throw "An odd number was passed";
    for(int i = 0; i < maxLength-1; i++){
        if(bigNumber::data[i] % 2 == 0){
            bigNumber::data[i] = (val) bigNumber::data[i]/2;
        }
        else{
            bigNumber::data[i] = (val) (bigNumber::data[i]-1)/2;
            bigNumber::data[i-1] = bigNumber::data[i-1] + (val) maxNum/2;
        }
    }
}
void bigNumber::display_number(void){
    bool startedDisplaying = false;
    std::cout << "\n";
    for(int i = maxLength-1; i >= 0; i--){
        if(!startedDisplaying){
            if(data[i] != 0){
                startedDisplaying = true;
                std::cout << data[i];
            }
        }
        else{
            val num = data[i];
            std::string zeros = "";
            int digits;
            for(digits = 0; num > 0; digits++) num = num/10;
            for(int z = 0; z < lengthNum - digits; z++) zeros = zeros + "0";
            std::cout << zeros;
            std::cout << data[i];
        }
    }
    std::cout << "\n";

}
bool bigNumber::equal_to_one(void){
    if(bigNumber::data[0] == 1){
        for(int i = maxLength-1; i > 0; i--) if(data[i] != 0) return 0;
        return 1;
    }
    return 0;
}

void bigNumber::display_number(val * Data){
    bool startedDisplaying = false;
    std::cout << "\n";
    for(int i = maxLength-1; i >= 0; i--){
        if(!startedDisplaying){
            if(Data[i] != 0){
                startedDisplaying = true;
                std::cout << Data[i];
            }
        }
        else{
            val num = Data[i];
            std::string zeros = "";
            int digits;
            for(digits = 0; num > 0; digits++) num = num/10;
            for(int z = 0; z < lengthNum - digits; z++) zeros = zeros + "0";
            std::cout << zeros;
            std::cout << Data[i];
        }
    }
    std::cout << "\n";
}
