#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>


/*
* @pre filename != NULL
* @post return 0 if the file {filename} exist. -1 Otherwise.
*/
int file_exists(char *filename) {
    int repFile = open(filename, O_RDONLY);
    if (repFile == -1) return -1;
    close(repFile);
    return 0;
}

typedef struct point {
    int x;
    int y;
    int z;
} point_t;

/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename) {
    int idFile = open(filename, O_RDWR | O_CREAT | O_TRUNC);
    if (idFile == -1) return -1;

    int ftrRep = ftruncate(idFile, sizeof(pt)*size);
    if (ftrRep == -1) return -6;

    void *mem = mmap(NULL, sizeof(point_t)*size, PROT_READ | PROT_WRITE, MAP_SHARED, idFile, 0) ; 
    if (mem == (void*)-1) {
        return -3 ;
    }
    memcpy (mem, pt, sizeof(point_t)*size);
    int fin = msync(mem,sizeof(point_t)*size, MS_ASYNC);
    if (fin == -1) {
        return -5 ; 
    }
    int cl = munmap(mem,sizeof(point_t)*size); 
    if (cl == -1){ 
    return -4 ;
    }
    int fc = close(idFile) ; 
    if ( fc == -1 ){
        return -2 ;
    }

    return 0 ;
}

/*
 * @pre filename != NULL, name of the file
 * @post returns the sum of all integers stored in the binary file.
 *       return -1 if the file can not be open.
 *       return -2 if the file can not be closed.
 *       return -3 if mmap() fails.
 *       return -4 if munmap() fails.
 *       return -5 if fstat() fails.
 */
int sum_file(char *filename) {
    
}


int main() {
    char* filename = "FileExists.exe";
    printf("%d \n", open(filename, O_RDONLY));
    printf("%d \n", file_exists(filename));

    char* filenameSave = "FileSave.txt";
    point_t *pt = malloc(sizeof(point_t));
    pt->x = 4;
    pt->y = 5;
    pt->z = 6;
    int size = 10;
    printf("%d \n",save(pt, size, filenameSave));

}