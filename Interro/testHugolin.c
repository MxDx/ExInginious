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

struct stacknode* push(struct stacknode *s, Item i){
    if(s==NULL||s==NULL){
    return NULL;
    }
    struct stacknode* nw = malloc(sizeof(struct stacknode));
    if(nw==NULL){
        return NULL;
    }
    nw->item = i;
    nw->next = *s;
    *s = nw;
    return nw;
}

Item pop(struct stacknode *s){
    Item a = (s)->item;
    struct stacknode *t = *s;
    s = (s)->next;
    free(t);
    return a;
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