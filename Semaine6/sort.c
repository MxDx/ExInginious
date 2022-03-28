#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

typedef struct points {
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;

/*
* Function used to compare two structures based on their averages.
*
* @s1 : a pointer to the first structure
* @s2 : a pointer to the second structure
*
* @return an integer less than, equal to, or greater than zero if the first argument is considered to be
*        respectively less than, equal to, or greater than the second
*/
int compar(const void* s1, const void* s2) {
    return (int) ((((points_t*) s1)->average - ((points_t*)s2)->average)*1000);
}

/*
* Function used to update the file with the structures stored in it
*
* @filename : the path indicating where to find the file (!= NULL)
*
* @return 0 if no error
*        -1 if open failed
*        -2 if mmap failed
*        -3 if munmap failed
*        -4 if msync failed
*        -5 if fstat failed
*        -6 if close failed
*/
int sort(char* filename) {
    int fd = open(filename, O_RDWR);
    if (fd == -1 ) return -1;
    struct stat buf;

    if (fstat(fd,&buf) == -1 ) {
        close(fd);
        return -5;
    }

    size_t len = buf.st_size;
    points_t *adr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (adr == MAP_FAILED) {
        close(fd);
        return -2;
    }

    for (int i =0; i < len/sizeof(points_t); i++) {
        adr[i].average = (adr[i].LEPL1103+adr[i].LEPL1203 + adr[i].LEPL1108 + adr[i].LEPL1302 + adr[i].LEPL1402)/5;
    }

    qsort(adr, len/sizeof(points_t), sizeof(points_t), compar);
    if (msync(adr, len, MS_SYNC) == -1) {
        munmap(adr,len);
        close(fd);
        return -4;
    }

    if (munmap(adr, len) == -1 ) {
        close(fd);
        return -3;
    }

    if (close(fd) == -1 ) return -6;
    return 0;
}

int main() {

}