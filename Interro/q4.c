#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct set {
  struct node *first; // pointeur vers le premier node
  int n; // nombre total d'éléments (pas nécessairement distincts) dans l'ensemble
};

struct node {
  double real; // partie réelle
  double img; // partie imaginaire
  int count; // nombre d'éléments ayant cette valeur
  struct node *next; // pointeur vers le noeud suivant
};

/*
 * Exemple d'utilisation:
 *
 * // création d'un set vide
 * struct set set; set.n = 0; set.first = NULL;
 *
 * L'ensemble contient 5 nombres complexes
 * addr:0x603030 (2.300000,2.200000) count=2 next=0x603470
 * addr:0x603470 (2.300000,2.300000) count=2 next=0x6034a0
 * addr:0x6034a0 (2.200000,2.200000) count=1 next=(nil)
 * rm(2.3,2.3,&set)=4
 * L'ensemble contient 4 nombres complexes
 * addr:0x603030 (2.300000,2.200000) count=2 next=0x603470
 * addr:0x603470 (2.300000,2.300000) count=1 next=0x6034a0
 * addr:0x6034a0 (2.200000,2.200000) count=1 next=(nil)
 * rm(2.2,2.2,&set)=3
 * L'ensemble contient 3 nombres complexes
 * addr:0x603030 (2.300000,2.200000) count=2 next=0x603470
 * addr:0x603470 (2.300000,2.300000) count=1 next=(nil)
 * rm(2.3,2.2,&set)=2
 * L'ensemble contient 2 nombres complexes
 * addr:0x603030 (2.300000,2.200000) count=1 next=0x603470
 * addr:0x603470 (2.300000,2.300000) count=1 next=(nil)
 * rm(2.3,2.2,&set)=1
 * L'ensemble contient 1 nombres complexes
 * addr:0x603470 (2.300000,2.300000) count=1 next=(nil)
 * rm(2.3,2.2,&set)=1
 * L'ensemble contient 1 nombres complexes
 * addr:0x603470 (2.300000,2.300000) count=1 next=(nil)
 * rm(2.3,2.3,&set)=0
 * Ensemble vide
 * L'ensemble contient 0 nombres complexes
 */

/*
 * @pre set!=NULL
 * @post le nombre complexe (real,img) a été correctement
 *       retiré de l'ensemble set si il s'y trouvait. La variable n de cet
 *       ensemble contient à tout moment la quantité de
 *       nombres complexes dans l'ensemble (qui est équivalente à
 *       la somme des count de tous les éléments de la liste chainée).
 *       La fonction retourne la quantité de nombres complexes dans
 *       l'ensemble.
 */
int rm(double real, double img, struct set *set) {
    int nb = 0;
    struct node* current = set->first;
    if (current->img == img && current->real == real) {
        nb++;
        current->count--;
        set->n--;
        if (current->count == 0) {
            set->first = current->next;
            free(current);
        }
    }
    struct node* previous = current;
    current = current->next;

    for (int i = 1; i < set->n; i++) {
        if (current->img == img && current->real == real) {
            nb++;
            current->count--;
            set->n--;
            if (current->count == 0) {
                previous->next = current->next;
                free(current);
            }
        }
    }

    return nb;
}

int main() {
    struct set s;
    struct node *n1=(struct node*) malloc(sizeof(struct node));
    struct node *n2=(struct node*) malloc(sizeof(struct node));
    struct node *n3=(struct node*) malloc(sizeof(struct node));
    s.first=n1;
    s.n=5;
    n1->real=7.9;
    n1->img=2.9;
    n1->next=n2;
    n1->count=2;
    n2->real=7.4;
    n2->img=2.3;
    n2->next=n3;
    n2->count=1;
    n3->real=7.3;
    n3->img=2.5;
    n3->next=NULL;
    n3->count=2;

    printf("%f %f %d %d \n", s.first->img, s.first->real, s.first->count, s.n);
    rm(7.9, 2.9, &s);
    printf("%f %f %d %d \n", s.first->img, s.first->real, s.first->count, s.n);
    printf("%f %f %d %d \n", s.first->next->img, s.first->next->real, s.first->next->count, s.n);
    rm(7.4, 2.3, &s);
    printf("%f %f %d %d \n", s.first->next->img, s.first->next->real, s.first->next->count, s.n);
    rm(7.3, 2.5, &s);
    printf("%f %f %d %d \n", s.first->img, s.first->real, s.first->count, s.n);
}