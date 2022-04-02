#include <stdio.h>
#include <limits.h>

struct s {
    float f;
    int id;
};


struct s tab[]={
    {1.23, 12},
    {1.23, 94},
    {4.56, 12},
    {1.23, 12}
};

/**
* @pre tab est un pointeur vers un tableau,
* @pre elem une structure de type s et
* @pre size est la taille du tableau
* @post: retourne le nombre d'éléments du tableau qui sont égaux à elem
**/
int fTab(struct s *tab, struct s elem, unsigned int size) {
    int occ = 0;

    for (int i = 0; i < size; i++) {
        if (tab[i].f == elem.f && tab[i].id == elem.id) {
            occ++;
        }
    }

    return occ;
}

int main() {
    struct s elem;
    printf("%f %d \n", elem.f, elem.id);
    printf("%d \n", fTab(tab, elem, 4));
}