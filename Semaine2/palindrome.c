#include <string.h>
#include <stdio.h>
/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str) {
    if (str == NULL) {
        return -1;
    }
    if (strlen(str) > 50) {
        return 1 ;
    }

    char cleanStr[(strlen(str)+1)];
    int n = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] != ' ') {
            cleanStr[n++] = str[i];
        }
    }

    cleanStr[n] = '\0';
    for(int i = 0; i<strlen(cleanStr)/2; i++) {
        if (cleanStr[i] != cleanStr[n-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv) {
    char* test = "Maxime";
    char* palindrome = "ka yak";
    char stri[(strlen(palindrome)+1)*sizeof(char)];
    char str[strlen(palindrome)+1];
    strcpy(stri, palindrome);
    
    printf("test : %c \n", test[3]);
    printf("Mot qu'on test : %s \n", palindrome);
    printf("palindrome : %d \n", pal(palindrome));
}