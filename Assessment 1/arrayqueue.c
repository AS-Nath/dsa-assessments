#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

struct Queue {
    int n;
    int front;
    int rear;
    int *arr;
}; 

void enqueue(struct Queue* q, int v);
int dequeue(struct Queue* q); 
void display(struct Queue*); 

int main(void) {
    struct Queue q;
    int qsize = 0;
    printf("Enter Queue Size : "); 
    scanf("%d", &qsize); 
    q.n = qsize;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)calloc(q.n, sizeof(int)); 
    while (true) {
        printf("Enter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display\n");
        printf("Enter any other integer to Exit\n");
        int c;
        scanf("%d", &c); 
        switch(c) {
            case 1 : 
                printf("Enqueue Value : ");
                int x;
                scanf("%d", &x);
                enqueue(&q, x);
                break; 
            case 2 : 
                dequeue(&q);
                break; 
            case 3 : 
                display(&q); 
                break; 
            default :
                free(q.arr); 
                return 0; 
        }
    }
    free(q.arr); 
    return 0; 
}

void enqueue(struct Queue* q, int v) {
    if ((q -> rear) == (q -> n) - 1) {
        printf("Queue is full.\n"); 
    }
    else if (q -> rear == -1 && q -> front == -1) {
        q -> rear = 0; q -> front = 0;
        q -> arr[q -> rear] = v; 
        printf("Enqueued %d!\n", v); 
    }
    else {
        q -> rear += 1;
        q -> arr[q -> rear] = v; 
        printf("Enqueued %d!\n", v);
    }
}

int dequeue(struct Queue* q) {
    if (q -> rear == -1 && q -> front == -1) {
        printf("Queue is empty.\n");
    }
    else {
        int x = q -> arr[q -> front]; 
        q -> front += 1;
        if (q -> front > q -> rear) {
            q -> front = -1;
            q -> rear = -1; 
        }
        return x; 
    }
}

void display(struct Queue* q) {
    printf("Queue Elements : \n"); 
    for (int i = q -> front; i <= q -> rear; i++) {
        printf("%d ", q -> arr[i]);
    }
    printf("\n");
}