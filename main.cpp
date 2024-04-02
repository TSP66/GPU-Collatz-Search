#include <climits>
#include <string>
#include "bigNumber.h"
#include "search.h"

//#include "search.h"

//Max possible number = 10^(19,000) or ~2^(63,000)

int main() {
    bigNumber number;
    number.addition(12603);
    number.data[9999] = 3005436;
    number.display_number();
    //num.data[1] = 16;
    //search num(number);
    //num.num.display_number();
    //num.modulus(6);
    //std::cout << num.startToOne();
    return 0;
}