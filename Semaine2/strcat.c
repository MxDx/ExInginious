#include <stdio.h>
#include <string.h>

char* strcat(char* dest, const char* src) {
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    return dest;
}

int main(int argc, char *argv[]) {
    //int testInteger;
    //printf("Enter an integer: ");
    //scanf("%d", &testInteger);  
    //printf("Number = %d",testInteger);
    char* testPointeur = "Hello";
    char* src = "sam la pute";
    char* rep = strcat(testPointeur, src);
    printf("pute");
    printf("%s \n",rep);
    return 0;
}