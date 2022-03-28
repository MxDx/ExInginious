#include <stdio.h>

struct fract_t {
        int num;
        int denum;
    };

int main(int argc, char* argv) {
    struct fract_t a = {1, 2};
    struct fract_t b = {1, 4};

    struct fract_t* aPointeur = &a;
    struct fract_t* bPointeur = &b;

    printf("Denum de a = %d \n", a.denum);
    printf("Denum de b = %d \n", b.denum);

    swap(aPointeur, bPointeur);

    printf("Denum de a = %d \n", a.denum);
    printf("Denum de b = %d \n", b.denum);
}

void swap(struct fract_t *a, struct fract_t *b) {
    int tmpNum = (*a).num;
    int tmpDenum = (*a).denum;
    (*a).num = (*b).num;
    (*a).denum = (*b).denum;
    (*b).num = tmpNum;
    (*b).denum = tmpDenum;
}