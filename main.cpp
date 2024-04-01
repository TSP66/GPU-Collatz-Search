#include <iostream>
#include <cmath>
#include <climits>

typedef unsigned long long int val;

const int maxLength = 10;
const val maxNum = pow(10,3);//pow(10,19);

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
        int pos = 0;
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
                Data[0] = Data[0] - value;
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
            subtraction(copy,value);
            //display_number();
            
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
                if(data[i] > 100) std::cout << data[i];
                else if(data[i] > 10) std::cout << "0" << data[i];
                else std::cout << "00" << data[i];
            }
        }
        std::cout << "\n";

    }

};

int main() {
    bigNumber num;
    num.data[1] = 6;
    std::cout << num.data[maxLength-1];
    num.addition(603);
    //num.modulus(6);
    std::cout << num.modulus(6);
    return 0;
}