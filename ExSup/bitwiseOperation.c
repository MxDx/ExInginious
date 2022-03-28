#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printBits(unsigned int num)
{
   for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
   {
      printf("%i ", num & 0x01);
      num = num >> 1;
   }
}

void showbits( uint8_t x ){
    int i=0;
    printf("0b");
    for (i = (sizeof(uint8_t) * 8) - 1; i >= 0; i--){
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

void showbits32( uint32_t x ){
    int i=0;
    printf("0b");
    for (i = (sizeof(uint32_t) * 8) - 1; i >= 0; i--){
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

uint8_t bitwiseOpTest(uint8_t x) {
    uint8_t test;
    for (int i = 0; i < 8; i++) {
        test = x & 0x01;
    }
    return 1;
}

uint8_t get_3_leftmost_bits(uint32_t x) {
    uint8_t rep, temp;
    temp = (uint8_t) (x >> 24);
    for (int i = 0; i < sizeof(uint8_t)*8; i++) {
        rep += (temp & (1u << i) ? 1 : 0);
    }
    return rep;
}

uint8_t get_4_rightmost_bits(uint32_t x) {
    uint8_t rep = (uint8_t) x << 28;
    return rep; 
}

int main(int argc,  char* argv) {
    uint8_t* a = malloc(sizeof(uint8_t));
    *a = 4;
    uint8_t* b = malloc(sizeof(uint8_t));
    *b = 2;
    printf("%d\n", *a ^ *b);

    unsigned int bit1Int = 217;
    uint8_t bit1 = 0b11011001;
    uint32_t bit2 = 0b11011001000000000000000000000001; 
    uint32_t bit1In32 = (uint32_t) bit1;
    uint8_t bit2To8 = (uint8_t) bit2;
    uint8_t bit2To8Transfo = (uint8_t) (bit2 >> 24);
    uint8_t bit3 = bit2To8Transfo & (1 << 0);
    uint8_t bit4 = get_4_rightmost_bits(bit2);
    putchar(bit2To8Transfo & (1u << 0) ? '1' : '0');
    printf("\n");
    if (bit3) {
        printf("true \n");
    }
    else {
        printf("false \n");
    }
    printf("%d\n", get_3_leftmost_bits(bit2));
    //printf("%2X \n", bit1); 
    //printf("%d \n", bit1);
    //showbits(bit1);
    //showbits32(bit2);
    //showbits32(bit1In32);
    //showbits(bit2To8);
    //showbits32(bit2To8);
    showbits(bit2To8Transfo);
    showbits(bit3);
    showbits(bit4);
    //printBits(bit1Int);
    //uint8_t repBitwise = bitwiseOpTest(bit1); 
}