#include <stdlib.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) {
    int i;
    for (i = 0; i < 10; i++) {
        void *rep = malloc(s); 
        if (rep != NULL) {
            return rep;
        }
        sleep(5);
    }

    return NULL;
}

int main(int argc, char *arv) {

}