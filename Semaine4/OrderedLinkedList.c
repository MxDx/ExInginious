#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) {
    if (a == b) return 0;
    else if (a < b) return -1;
    else return 1;
}

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) {
    node_t* newNode = malloc(sizeof(node_t));
    if (newNode == NULL) return -1;
    newNode->val = val;

    if ((*head) == NULL) {
        *head = newNode;
        newNode->next = NULL;
        return 0;
    }
    if (cmp(val,(*head)->val) < 0) {
        newNode->next = *head;
        head = &newNode;
        return 0;
    }

    node_t* current = *head;
    while(current->next != NULL) {
        if (cmp(val, current->next->val) == 0) return 0;
        else if (cmp(val,current->next->val) < 0) {
            newNode->next = current->next;
            current->next = newNode;
            return 0;
        }
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
    return 0;
}

int main() {
    char a = 'a';
    char b = 'b';

    //node_t* node1 = malloc(sizeof(node_t));
    node_t* node1 = NULL;
    node_t** head = &node1;
    //node1->next = NULL;
    //node1->val = a;



    printf("%d \n", insert(head, a, compare));
    printf("%c \n", (*head)->next->val);

    printf("%d \n", insert(head, b, compare));
    printf("%c \n", (*head)->next->val);

    printf("%d \n", insert(head, 'c', compare));
    printf("%c \n", (*head)->next->next->val);

    printf("%d \n", insert(head, 'e', compare));
    printf("%c \n", (*head)->next->next->next->val);

    printf("%d \n", insert(head, 'd', compare));
    printf("%c \n", (*head)->next->next->next->val);
}