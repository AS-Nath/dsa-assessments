#include <stdio.h>
#include <stdlib.h>

/*
Parameters : 
We'll maintain a stack whose size can be initialised at the start and not again. 
We can push, pop, and display from top. 
*/

struct Stack {
    int n; // Size
    int top; // Top
    int *arr; // Elements
};

void push(struct Stack* st, int v);
void pop(struct Stack* st);
void display(struct Stack* st); 

int main(void) {
    struct Stack st;
    st.n = 5;
    st.top = -1; 
    st.arr = (int *)calloc(st.n, sizeof(int)); 
    // We'll perform operations from here.
    pop(&st); // We expect overflow negative direction 
    push(&st, 1); 
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    push(&st, 6); // We expect an overflow 
    display(&st);
    free(st.arr);
    return 0;
}

void push(struct Stack* st, int v) {
    if (st -> top == (st -> n) - 1) {
        printf("Stack is full.\n"); 
    }
    else {
        st -> top += 1;
        st -> arr[st -> top] = v;
        printf("Pushed %d to stack\n", v); 
    }
}

void pop(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n"); 
    }
    else {
        printf("Popped %d\n", (st -> arr[st -> top]));
        st -> top -= 1; 
    }
}

void display(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack Values : <top to bottom> \n"); 
        for (int i = st -> top; i >= 0; i--) {
            printf("%d ", st -> arr[i]);
        }
        printf("\n"); 
    }
}