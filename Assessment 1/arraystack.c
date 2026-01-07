#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Parameters : 
We'll maintain a stack whose size can be initialised at the start and not again. 
We can push, pop, and display from top. 
*/

struct Stack {
    int n; 
    int top; 
    int *arr; 
};

void push(struct Stack* st, int v);
void pop(struct Stack* st);
void display(struct Stack* st); 

int main(void) {
    struct Stack st;
    int stacksize = 0;
    printf("Enter Stack Size : "); 
    scanf("%d", &stacksize); 
    st.n = stacksize;
    st.top = -1; 
    st.arr = (int *)calloc(st.n, sizeof(int)); 
    while (true) {
        printf("Enter 1 to Push\n");
        printf("Enter 2 to Pop\n");
        printf("Enter 3 to Display\n");
        printf("Enter any other integer to Exit\n");
        int c;
        scanf("%d", &c); 
        switch(c) {
            case 1 : 
                printf("Push Value : ");
                int x;
                scanf("%d", &x);
                push(&st, x);
                break; 
            case 2 : 
                pop(&st);
                break; 
            case 3 : 
                display(&st); 
                break; 
            default :
                free(st.arr); 
                return 0; 
        }
    }
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
    } // Full Ascending Stack. If not full, increment the top and push.
}

void pop(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n"); 
    }
    else {
        printf("Popped %d\n", (st -> arr[st -> top]));
        st -> top -= 1; 
    } // If not empty, remove the element and decrement the top. 
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
    } // Display from top to bottom if the stack has elements. 
}