#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src) {
    if (src == NULL) {
        return NULL;
    }

    char *buf = malloc(strlen(src)+1);
    if (buf == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; src[i]; i++) {
        buf[i] = src[i];
    }
    buf[i] = '\0';
    return buf;
}

int main(int argc, char* argv[]) {
    //char *test;
    //char chara = "test";
    //*test = &chara;
    char* test = "Maxime";
    char *buf = buf_strcpy(test);
    printf("test = %s \n", test);
    printf("Buf = %s \n", buf);
}