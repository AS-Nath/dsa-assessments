#include <stdio.h>
#include <stdlib.h> 

struct Queue {
    int n;
    int front;
    int rear;
    int *arr;
}; 

void push(struct Queue* q, int v);
int pop(); 
void display(struct Queue*); 

int main(void) {
    struct Queue q;
    q.n = 7;
    q.front = -1;
    q.rear = -1;
    q.arr = (int *)calloc(q.n, sizeof(int)); 
    push(&q, 1); 
    push(&q, 2); 
    push(&q, 3); 
    push(&q, 4); 
    push(&q, 5); 
    printf("Popped %d!\n", pop(&q));
    printf("Popped %d!\n", pop(&q));
    printf("Popped %d!\n", pop(&q));
    display(&q); 
}

void push(struct Queue* q, int v) {
    if ((q -> rear) == (q -> n) - 1) {
        printf("Queue is full.\n"); 
    }
    else if (q -> rear == -1 && q -> front == -1) {
        q -> rear = 0; q -> front = 0;
        q -> arr[q -> rear] = v; 
        printf("Pushed %d to queue!\n", v); 
    }
    else {
        q -> rear += 1;
        q -> arr[q -> rear] = v; 
        printf("Pushed %d to queue!\n", v);
    }
}

int pop(struct Queue* q) {
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