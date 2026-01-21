#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next; 
}; 

void display(struct Node* head) {
    struct Node* travNode = head;
    printf("Linked List Elements : ");
    while (travNode != NULL) {
        printf("%d ", travNode -> data); 
        travNode = travNode -> next; 
    }
    printf("\n"); 
}

void delete(struct Node** head, int position) {
    struct Node* travNode = *head;
    if (*head == NULL) {
        printf("Linked List is empty.\n"); 
    }
    else if (position == 1) {
        struct Node* newhead = travNode -> next; 
        *head = newhead; 
        free(travNode);
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
            free(delNode);
            printf("Deleted %d from Linked List!\n", v); 
        }
    }
}

bool search(struct Node** head, int target) {
    if (*head == NULL) {
        printf("Linked List is empty. Nothing to search.\n"); 
        return false; 
    }
    else {
        struct Node* travNode = *head;
        while (travNode != NULL) {
            if (travNode -> data == target) {
                return true; 
            }
            travNode = travNode -> next; 
        }
        return false; 
    }
}

void reverse(struct Node** head) {
    if (*head == NULL) {
        printf("Linked List is empty.\n"); 
    } 
    else {
        struct Node* prev = NULL;
        struct Node* travNode = *head;
        struct Node* travNext = NULL; 
        while (travNode != NULL) {
            travNext = travNode -> next; 
            travNode -> next = prev;
            prev = travNode; 
            travNode = travNext; 
        }
        *head = prev; 
    }
}

void insert(struct Node** head, int n, int position) {
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
        printf("Enter 1 to insert in the Linked List.\n");
        printf("Enter 2 to delete from the Linked List.\n"); 
        printf("Enter 3 to search the Linked List for some element.\n"); 
        printf("Enter 4 to reverse the Linked List.\n");
        printf("Enter 5 to display the Linked List.\n"); 
        printf("Enter any other integer to exit.\n"); 
        int c;
        scanf("%d", &c);
        switch (c) {
            case 1 : 
                printf("Enter value to insert : "); 
                int v;
                scanf("%d", &v); 
                printf("Enter position (1-indexed) to insert at : "); 
                int pos;
                scanf("%d", &pos); 
                insert(&head, v, pos); 
                printf("Inserted %d at position %d!\n", v, pos); 
                break;
            case 2 : 
                printf("Enter index to delete from : "); 
                int index;
                scanf("%d", &index);
                delete(&head, index);
                break;
            case 3 : 
                printf("Enter search target : ");
                int target;
                scanf("%d", &target); 
                if (search(&head, target)) {
                    printf("%d was found!\n", target);
                }
                else {
                    printf("%d was not found!\n", target); 
                }
                break;
            case 4 : 
                reverse(&head);
                printf("Linked List was reversed!\n"); 
                break;
            case 5 : 
                display(head);
                break;
            default : 
                return 0; 
        }  
    }    
    return 0; 
}