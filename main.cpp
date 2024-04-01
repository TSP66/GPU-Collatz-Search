#include <iostream>
#include <cmath>
#include <climits>
#include <string>

typedef unsigned long long int val;

const int maxLength = 10100;
const int lengthNum = 18; //val can hold up to 19 digit numbers, but if it is set to 18, 
//it means it can be used for calcuations that briefly require more digits such as 3n+1
const val maxNum = pow(10,lengthNum);//pow(10,18);

//Max possible number = 10^(19,000) or ~2^(63,000)

class bigNumber{

    public:

    val data[maxLength] = { };
    
    void addition(unsigned long value){ //Not for negative numbers

        bool notFinished = true;
        int pos = 0;
        long append_value = value;

        while(notFinished){
            val sum = data[pos] + append_value;
            if(value >= maxNum){
                data[pos] = sum - maxNum;
                append_value = 1; // Only possible to carry one over
                pos++;
            }
            else{
                data[pos] = sum;
                notFinished = false;
                break;
            }
        }
    }

    bool odd(void){
        if(data[0] % 2 == 1) return 1;
        return 0;
    }

    void three_nPlusOne(void){
        for(int i = maxLength-1; i >= 0; i--){
            if((i == maxLength-1) && (data[i] > maxNum/3)) throw "Not possible - need more length";
            if(data[i] < maxNum/3){
                data[i] = 3*data[i];
            }
            else{
                data[i+1] = data[i+1] + floor((3*data[i])/maxNum);
                data[i] = (3*data[i]) % maxNum;
            }
        }
        addition(1);
    }

    void divideTwo(void){
        if(odd() == 1) throw "An odd number was passed";
        for(int i = 0; i < maxLength-1; i++){
            if(data[i] % 2 == 0){
                data[i] = (val) data[i]/2;
            }
            else{
                data[i] = (val) (data[i]-1)/2;
                data[i-1] = data[i-1] + (val) maxNum/2;
            }
        }

    }
    void display_number(void){
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

    bool equal_to_one(void){
        if(data[0] == 1){
            for(int i = maxLength-1; i > 0; i--) if(data[i] != 0) return 0;
            return 1;
        }
        return 0;
    }

    void display_number(val * Data){
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

};

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

int main() {
    bigNumber number;
    number.addition(603);
    number.data[9999] = 3005436;
    //num.data[1] = 16;
    search num(number);
    num.num.display_number();
    //num.modulus(6);
    std::cout << num.startToOne();
    return 0;
}