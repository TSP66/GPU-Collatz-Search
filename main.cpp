#include <iostream>
#include <cmath>
#include <climits>
#include <string>

typedef unsigned long long int val;

const int maxLength = 10;
const int lengthNum = 19;
const val maxNum = pow(10,lengthNum);//pow(10,19);

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
    void subtraction(val * Data, unsigned long value){ //Not for negative numbers

        bool notFinished = true;
        long append_value = value;

        if(allbutone(Data)){
            if(Data[0] >= value){
                Data[0] = Data[0] - value;
            }
            else{
                throw std::invalid_argument("Input is greater than number - negative numbers are not allowed");
            }
        }
        else{
            if(Data[0] >= value){
                Data[0] = Data[0]-value;
            }
            else{
                bool notbroken = true;
                int carray_over = 0;
                int pos = 1;
                while(notbroken){
                    if(Data[pos] == 0){
                        Data[pos] = maxNum - 1;
                    }
                    else{
                        Data[pos] = Data[pos]-1;
                        Data[0] = maxNum - (value - Data[0]);
                        notbroken = false;
                        break;
                    }
                    pos++;

                }
            }

        }
    }

    bool allbutone(val * Data){
        for(int i = maxLength-1; i > 0; i--){
            if(Data[i] != 0){ 
                return(0);
            };
        }
        return(1);
    }

    int modulus(long value){

        val copy[maxLength] = {};

        std::copy(std::begin(data), std::end(data), std::begin(copy));

        while(!allbutone(copy)){
            for(int i = maxLength-1; i >= 0; i--) copy[i] = copy[i] % value;
            subtraction(copy,value);
            //display_number(copy);
        }

        return(copy[0]%value);
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

int main() {
    bigNumber num;
    num.data[2] = 3006;
    num.data[1] = 6;
    num.addition(604);
    //num.modulus(6);
    num.display_number();
    std::cout << num.modulus(5);
    return 0;
}