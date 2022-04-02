#include <stdio.h>
#include <stdlib.h>

typedef int Item;  // donnée stockée
struct stacknode{   // élement
    Item item;
    struct stacknode * next;
};

/**
 *  @pre head != NULL
 *  @post *head = NULL
 **/
void init_stack_sol(struct stacknode **head){
    *head = NULL;
}

/**
 *  @pre s != NULL
 *  @post un nouveau noeud est crée et renvoyé ayant pour item i
 *  le nouveau noeud devient le head
 **/
struct stacknode* push(struct stacknode **s, Item i) {
    struct stacknode* newNode = malloc(sizeof(struct stacknode*));
    if (newNode == NULL) return NULL;
    newNode->item = i;
    if (*s == NULL) {
        newNode->next = NULL;
        *s = newNode;
        return newNode;
    } else {
        newNode->next = (*s);
        *s = newNode;
        return newNode; 
    }  
}

/**
 * @pre s!=NULL
 * @post retourne l'item du noeud en tête de liste
 * l'élement suivant devient la tête de liste
 **/

Item pop(struct stacknode **s) {

    Item rep = (*s)->item;
    struct stacknode* oldHead = (*s); 
    (*s) = (*s)->next;
    free(oldHead);

    return rep;
}

int main() {
    struct stacknode** head = malloc(sizeof(struct stacknode**));
    init_stack_sol(head);
    Item test = 10;
    printf("%d \n", test);

    struct stacknode* pushStack = push(head, test);
    printf("%d \n", pushStack->item);

    Item test2 = 11;
    printf("%d \n", test2);

    struct stacknode* pushStack2 = push(head, test2);
    printf("%d \n", (*head)->next->item);

    printf("%d \n", (*head)->item);
    printf("%d \n", pop(head));
    printf("%d \n", (*head)->item);
}