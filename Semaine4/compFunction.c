#include <stdio.h>
#include <stdint.h>

uint8_t testFunction(uint8_t nb) {
    if (nb > 124) {return 1;}
    return 0;
}


int cmp_func(uint8_t func1(uint8_t), uint8_t func2(uint8_t)) {
    if (func1 == func2) return 1; 
    for (unsigned int i = 0; i<256; i++) {
        if (func1(i)==func2(i)) continue;
        else {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char* argv) {
    uint_8 testFunctionPointer(uint8_t) = testFunction;
    printf("%d \n", cmp_func(testFunction,testFunction));
    printf("%d \n", (*testFunctionPointer)(125));

}