#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result) {
    if (head == NULL | *head == NULL) {
        return 1;
    } else {
        result = malloc(sizeof((*head)->name));
        if (result == NULL) {
            return 1;
        }
        strncpy(result, (*head)->name, strlen((*head)->name)+1);
        free((*head)->name);
        struct node* oldHead = *head;
        (*head) = (*head)->next;
        free(oldHead);
        return 0;
    }
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value) {
    if (head == NULL) {
        return 1;
    } else {
        struct node newNode;
        newNode.name = malloc(strlen(value));
        if (newNode.name == NULL) {
            return 1;
        }
        strcpy(newNode.name, value);
        if (*head == NULL) {
            newNode.next = NULL;
            *head = &newNode;
            return 0;
        } else {
            newNode.next = (*head);
            *head = &newNode;
            return 0; 
        }  
    } 
}

int main(int argc, char *argv) {
    struct node* stack = malloc(sizeof(struct node));
    struct node** head = &stack;
    stack->name = "Sam la pute";
    struct node* nextNode = malloc(sizeof(struct node));
    stack->next = nextNode;
    nextNode->name = "Next node";
    printf("Node name = %s \n", stack->name);
    char* oldHeadName = malloc(sizeof(char));
    pop(head, oldHeadName);
    printf("Node name = %s \n", (*head)->name);
    push(head,"Sam la grosse pute");
    printf("Node name = %s \n", (*head)->name);
}