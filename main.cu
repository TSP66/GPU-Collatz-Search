#include <iostream>

#define BUFFER_SIZE 128 //Corresponds to a max number of 2^128
#define JOBS_THREAD 1024
#define BLOCK_SIZE 32
#define thread_x threadIdx.x
#define block_x blockIdx.x

__device__ void intToBin(bool * array, long long int value){
    int count = 0;
    for (int i = value; i > 0; i >>= 1){
        array[count++] = i%2;
    }
}

__device__ void plusOne(bool * array){
    bool carry = true;
    int pos = 0;
    while(carry){
        bool new_carry = array[pos] && carry;
        array[pos] = array[pos] || carry;
        carry = new_carry;
        pos++;
    }
}

__device__ void addition(bool * array, const bool * array2, bool carry){
    for (int i = BUFFER_SIZE; i > 0; i--){
        int sum = array[i]+array2[i]+carry;
        carry = (sum > 1);
        array[i] = (sum % 2);
    }
}

__device__ void divideTwo(bool * array){
    for (int i = BUFFER_SIZE - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
}

__device__ void timesThreeOne(bool * array){
    bool copy[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++)
        copy[i] = array[i];
    addition(array,copy,false);
    addition(array,copy,true);
}

__device__ void timesThreeOneDivideTwo(bool * array){
    timesThreeOne(array);
    divideTwo(array);
}

__device__ void isOne(bool * array){
    if (!array[BUFFER_SIZE-1]) return false;
    for (int i = 0; i < BUFFER_SIZE-1; i++){
        if (array[i]){
            return false;
        }
    }
}


__device__ void search(const bool * start){

    int jobs = JOBS_THREAD-1;
    long long int count = 0;
    bool current_number[BUFFER_SIZE];
    long long int trips[BUFFER_SIZE];

    bool array[BUFFER_SIZE];

    for (int i = 0; i < BUFFER_SIZE; i++){
        current_number[i] = start[i];
        array[i] = start[i]
    }

    while(jobs > 1){

        if (array[BUFFER_SIZE-1]){
            timesThreeOneDivideTwo(array);
        } else {
            divideTwo(array);
        }
        if (isOne(array)){
            trips[jobs] = count;
            plusOne(current_number);
            for (int i = 0; i < BUFFER_SIZE; i++){
                array[i] = current_number[i];
            }
            jobs--;
        }
        count++;
    }
}

__global__ void colatz_search(const bool * start){

}

int main(){
    return 0;
}