#include <stdio.h>

int first(void *ptr) {
    int *loc = ptr+12;
    return *loc;
}

char second(void *ptr) {
    char* loc = ptr+6;
    return *loc;
}

int third(void *ptr) {
    int *loc = ptr+45;
    return *loc;
}

int main(int argc, char* argv[]) {
    int i;
    void *ptr = &i - 12;
    int *loc = ptr+12;
    printf("ptr = %p \n", ptr);
    printf("loc = %p \n", loc);
    *loc = 4;
    printf("loc = %d \n", first(ptr));
}