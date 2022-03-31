#include <stdio.h>
#include <pthread.h>

pthread_mutex_t globalMutex = 0;

void inc() {
    globalMutex++;
}

/*
* Function used to protect a global variable used in the function inc().
*
* @inc : the function that must be called in critical (= protected) section
* @nb : the number of times the function inc() has to be called
* @mutex : an initialised mutex that has to be used for the protection
*
* @return 0 if no error, -1 otherwise
*/
int protect(void inc(void), int nb, pthread_mutex_t* mutex)  {
    for (int i = 0; i < nb; i++) {
        int l = pthread_mutex_lock(mutex);
        if (l != 0) return -1;
        inc();
        int u = pthread_mutex_unlock(mutex);
        if (u != 0) return -1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    protect(inc, argv[1], &global_Mutex);
}