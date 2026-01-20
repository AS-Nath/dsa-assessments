#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Deque {
    int n;
    int front; 
    int rear;
    int* arr;
} Deque; 

void display(Deque* dq) {
    if (dq -> front == -1 && dq -> rear == -1) {
        printf("Deque is empty.\n"); 
    }
    else {
        printf("Deque Elements (front to back) : "); 
        int i = dq -> front; 
        while (i != dq -> rear) {
            printf("%d ", dq -> arr[i]);
            i = (i + 1) % (dq -> n); 
        }
        printf("%d\n", dq -> arr[i]);
    } 
}

void push_front(Deque* dq, int v) {
    if (dq -> front == -1 && dq -> rear == -1) {
        dq -> front = 0;
        dq -> rear = 0; 
        dq -> arr[dq -> front] = v;
        printf("Pushed %d to Deque front!\n", v);
    } 
    else if (dq -> front - dq -> rear == 1) {
        printf("Deque full.\n"); 
    }
    else if (dq -> front == 0) {
        if (dq -> rear == dq -> n - 1) {
            printf("Deque full.\n");
        } 
        else {
            dq -> front = (dq -> n) - 1;
            dq -> arr[dq -> front] = v; 
            printf("Pushed %d to Deque front!\n", v); 
        }
    }
    else {
        dq -> front -= 1;
        dq -> arr[dq -> front] = v; 
        printf("Pushed %d to Deque front!\n", v); 
    }
}

int pop_front(Deque* dq) {
    if (dq -> front == -1 && dq -> rear == -1) {
        printf("Deque is empty.\n"); 
    }
    else if (dq -> front == dq -> rear) {
        printf("Popped %d from Deque front.\n", dq -> arr[dq -> front]); 
        int x = dq -> arr[dq -> front]; 
        dq -> front = -1;
        dq -> rear = -1; 
        return x;
    }
    else {
        printf("Popped %d from Deque front.\n", dq -> arr[dq -> front]);
        int x = dq -> arr[dq -> front]; 
        dq -> front = (dq -> front + 1) % dq -> n;
        return x; 
    }
    return -1;
}

void push_back(Deque* dq, int v) {
    if (dq -> front == -1 && dq -> rear == -1) {
        dq -> front = 0;
        dq -> rear = 0;
        dq -> arr[dq -> rear] = v;
        printf("Pushed %d to Deque rear!\n", v);
    }
    else if (dq -> front - (dq -> rear) == 1 || dq -> rear == dq -> n - 1 && dq -> front == 0) {
        printf("Deque full.\n"); 
    }
    else {
        if (dq -> rear == dq -> n - 1) {
            dq -> rear = -1; 
        }
        dq -> rear += 1;
        dq -> arr[dq -> rear] = v;
        printf("Pushed %d to Deque rear!\n", v);
    }
}

int pop_back(Deque* dq) {
    if (dq -> front == -1 && dq -> rear == -1) {
        printf("Deque is empty.\n"); 
    }
    else if (dq -> front == dq -> rear) {
        printf("Popped %d from Deque rear.\n", dq -> arr[dq -> rear]); 
        int x = dq -> arr[dq -> rear];
        dq -> rear = -1;
        dq -> front = -1;
        return x; 
    }
    else if (dq -> rear - dq -> front == 1) {
        printf("Popped %d from Deque rear.\n", dq -> arr[dq -> rear]); 
        int x = dq -> arr[dq -> rear];
        dq -> rear = -1;
        dq -> front = -1;  
        return x;
    }
    else {
        printf("Popped %d from Deque rear.\n", dq -> arr[dq -> rear]); 
        int x = dq -> arr[dq -> rear];
        if (dq -> rear == 0) {
            dq -> rear = dq -> n; 
        }
        dq -> rear -= 1; 
        return x;
    }
}

int main(void) {
    Deque dq;
    int size;
    printf("Enter Deque Size : "); 
    scanf("%d", &size); 
    dq.n = size;
    dq.front = -1;
    dq.rear = -1; 
    dq.arr = (int *)calloc(dq.n, sizeof(int)); 
    while (true) {
        printf("Enter 1 to push to the front.\n");
        printf("Enter 2 to pop from the front.\n");
        printf("Enter 3 to push to the rear.\n"); 
        printf("Enter 4 to pop from the rear.\n"); 
        printf("Enter 5 to display.\n"); 
        printf("Enter any other integer to exit.\n"); 
        int c;
        int v; 
        scanf("%d", &c); 
        switch (c) {
            case 1:
                printf("Enter push value : ");
                scanf("%d", &v);
                push_front(&dq, v); 
                break;
            case 2 : 
                pop_front(&dq); 
                break;
            case 3 : 
                printf("Enter push value : ");
                scanf("%d", &v);
                push_back(&dq, v); 
                break;
            case 4 : 
                pop_back(&dq); 
                break;
            case 5 : 
                display(&dq); 
                break;
            default:
                free(dq.arr); 
                return 0;
        }
    }
    return 0; 
}