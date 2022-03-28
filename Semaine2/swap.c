#include <stdio.h>

void swap(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
} 

int main(int argc, char* argv) {
    int val_i = 1;    
    int val_j = 2;
    int* i = &val_i;
    int* j = &val_j;
    printf("i = %d \n", *i);
    printf("j = %d \n", *j);
    swap(i, j);
    printf("i = %d \n", *i);
    printf("j = %d \n", *j);
}