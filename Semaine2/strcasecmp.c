#include <stdio.h>

int strcasecmp(const char *s1, const char *s2) {
    int i; 
    for (i = 0; s1[i] && s2[i]; ++i) 
    { 
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i]) 
           continue; 
        else
           break; 
    } 
    if (s1[i] == s2[i]) 
        return 0; 
    if ((s1[i] | 32) < (s2[i] | 32))  
        return -1; 
    return 1; 

}

int main(int argc, char* argv) {
    const char* s1 = "Luca la pute";
    printf("%d \n", s1[0]);
    printf("%d \n", (s1[0] ^ 32));
    printf("%d", strcasecmp(s1,s1));
}