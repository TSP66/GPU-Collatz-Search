#include <iostream>
#include <cmath>
#include <climits>

typedef unsigned long long int val;

const int maxLength = 1000;
const val maxNum = pow(10,19);

//Max possible number = 10^(19,000) or ~2^(63,000)

class bigNumber{

    public:

    val data[maxLength];
    
    void addition(long value){
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

};

int main() {
    bigNumber num;
    num.addition(5);
    std::cout << maxNum;
    return 0;
}