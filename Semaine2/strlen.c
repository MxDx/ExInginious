#include <string.h>
#include <stdio.h>

size_t strlen(const char* s) {
    size_t rep = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        rep++;
    }

    return rep;
}

int main(int argc, char* argv) {
    const char* testLen = "pute";
    size_t rep = strlen(testLen);
    printf("%d", rep);
}