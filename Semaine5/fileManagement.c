#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
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
    int fd = open(filename, O_RDONLY);
    if (fd == -1) return -1; 

    struct stat fileStat; 
    int fst = fstat(fd, &fileStat);
    if (fst == -1) return -5;

    int sizeFile = fileStat.st_size;
    if (sizeFile == 0) {
        int fc = close(fd);
        if (fc == -1) return -2;
        return 0;
    }

    int rep = 0;

    int* mem = mmap(NULL, sizeFile, PROT_READ, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) return -3;

    for (int i = 0; i < sizeFile/sizeof(int); i++) rep += mem[i];
    
    int unmap = munmap(mem, sizeFile);
    if (unmap == -1) return -4;

    int fc = close(fd);
    if (fc == -1) return -2;

    return rep;
}

/*
 * @pre filename != NULL, index >= 0
 * @post return the integer at the index {index}
 *       of the array in the file {filename}.
 *       return -1 in case of error.
 *       return -2 if index >= length of array.
 */
int get(char *filename, int index) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) return -1;

    struct stat fst;
    int fstRep = fstat(fd, &fst);
    if (fstRep == -1) return -1; 

    int size = fst.st_size;
    if (size/sizeof(int) <= index) {
        int fc = close(fd);
        if (fc == -1) return -1;
        return -2;
    }

    int* mem = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) return -1;

    int rep = mem[index];

    int unmap = munmap(mem, size);
    if (unmap == -1) return -1;

    int fc = close(fd);
    if (fc == -1) return -1;

    return rep;
}

/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value) {
    struct stat buf;
    int fd  =  open (filename , O_RDWR | O_CREAT ) ;
    if ( fd == -1) {
        return;
    }
    int size = fstat( fd , &buf ) ; 
    if ( size == -1){
       return ; 
    }
    size_t len = buf.st_size/sizeof(int);
    if ( index >= len ){ 
        close(fd);
        return ;
    }
    int *mem  = mmap (NULL, len*sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0) ; 
    if ( mem == MAP_FAILED ){
        return ; 
    }
    mem[index] = value ;   
    
    int unmem =  munmap( mem , len ) ; 
    if ( unmem == -1 ){
        return;
    }
    int fdc = close( fd) ;
    if ( fdc  == -1){
        return ;
    }
}

/*
 * @pre file_name != NULL, name of the original file
 *      new_file_name != NULL, name of the new file (the copy)
 *
 * @post copy the contents of {file_name} to {new_file_name}.
 *       return 0 if the function terminates with success, -1 in case of errors.
 */
int copy(char *file_name, char *new_file_name) {
    struct stat buf;
    int fd1 = open (file_name, O_RDONLY);
    if (fd1 < 0) {
      return -1;
    }

    int fst =fstat (fd1,&buf);
    if ( fst < 0) {
      return -1;
    }
    size_t size = buf.st_size ;
    if(size == 0 ){
        int f2 = open(new_file_name, O_CREAT | O_RDWR, buf.st_mode) ;
        if(f2 == -1) return -1 ;
        if(close(fd1) == -1) return -1;
        if(close(f2) == -1) return -1;
        return -1 ;
    }
    int *mp = mmap(NULL, size, PROT_READ, MAP_SHARED,fd1,0);
    if(mp == MAP_FAILED) return -1 ;

    int f2 = open(new_file_name, O_CREAT | O_RDWR, buf.st_mode) ;
    if(f2 == -1) return -1;

    if (ftruncate(f2,size) == -1) return -1 ;

    void *addr = mmap(NULL, size, PROT_WRITE,MAP_SHARED, f2, 0);
    if (addr == MAP_FAILED) return -1;

    memcpy(addr, mp, size) ;
    if (close(fd1) == -1 ) return -1;
    if (msync(addr, size, MS_SYNC) == -1 ) return -1;
    if (munmap(addr,size) == -1 ) return -1;
    if (close(f2) == -1 ) return -1;

    return 0;
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

    printf("%d \n", sum_file("testBin.bin"));
}