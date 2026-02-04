#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next; 
}; 

void display(struct Node* head) {
    struct Node* travNode = head;
    if (head == NULL) {
        printf("Stack is empty!\n"); 
    }
    else {
        printf("Stack Elements (top to bottom): ");
        while (travNode != NULL) {
            printf("%d ", travNode -> data); 
            travNode = travNode -> next; 
        }
        printf("\n"); 
    }
}

int pop(struct Node** head, int position) {
    struct Node* travNode = *head;
    if (*head == NULL) {
        printf("Stack is empty.\n"); 
        return -1;
    }
    else if (position == 1) {
        struct Node* newhead = travNode -> next; 
        *head = newhead;
        int x = travNode -> data; 
        free(travNode);
        return x;
    }
    else {
        int c = 1; 
        while (travNode -> next != NULL && c != position - 1) {
            travNode = travNode -> next;
            c += 1;
        }
        if (travNode -> next == NULL) {
            printf("Delete position out of bounds.\n");
        }
        else {
            struct Node* delNode = travNode -> next; 
            int v = delNode -> data;
            travNode -> next = delNode -> next; 
            int x = delNode -> data;
            free(delNode);
            return x; 
        }
    }
}

void push(struct Node** head, int n, int position) {
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node)); 
    newnode -> data = n;
    if (*head == NULL) {
        newnode -> next = NULL; 
        *head = newnode; 
    }
    else if (position == 1) {
        newnode -> next = *head;
        *head = newnode; 
    }
    else {
        int c = 1;
        struct Node* travNode = *head;  
        while (travNode -> next != NULL && c != position - 1) {
            travNode = travNode -> next; 
            c += 1; 
        }
        newnode -> next = travNode -> next; 
        travNode -> next = newnode; 
    }
}

int main(void) {
    struct Node* head = NULL; 
    while (true) {
        printf("Enter 1 to push to the Linked Stack.\n");
        printf("Enter 2 to pop from the Linked Stack.\n"); 
        printf("Enter 3 to display the Linked Stack.\n"); 
        printf("Enter any other integer to exit.\n"); 
        int c;
        scanf("%d", &c);
        int v;
        switch (c) {
            case 1 : 
                printf("Enter value to push : ");
                scanf("%d", &v); 
                push(&head, v, 1); 
                printf("Pushed %d to Linked Stack!\n", v); 
                break;
            case 2 : 
                v = pop(&head, 1);
                if (v > 0) {
                    printf("Popped %d from Linked Stack!\n", v);
                }
                break;
            case 3 : 
                display(head);
                break;
            default : 
                return 0; 
        }  
    }    
    return 0; 
}