#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

struct Stack {
    int n;
    int top;
    char *arr; 
};


void push(struct Stack* st, int v);
char pop(struct Stack* st);
void display(struct Stack* st); 
int priority(char op); 

int main(void) {
    struct Stack st;
    st.n = 100;
    st.top = -1; 
    st.arr = (char *)calloc(st.n, sizeof(char)); 
    
    char *s = (char *)malloc(100 * sizeof(char));
    scanf("%s", s); 

    for (int i = 0; i < strlen(s); i++) {
        // Alphanumeric, open bracket, closed bracket, or operand.
        if (isalnum(s[i])) {
            printf("%c", s[i]);
        }
        else if (s[i] == '(') {
            push(&st, s[i]);
        }
        else if (s[i] == ')') {
            int x;
            while ((x = pop(&st)) != '(') {
                printf("%c", x);
            }
        }
        else {
            while (priority(s[i]) <= priority(st.arr[st.top])) {
                printf("%c", pop(&st));
            }
            push(&st, s[i]);
        }
        
    }
    while (st.top > -1) {
        printf("%c", pop(&st)); 
    }
    printf("\n");
    return 0;
}

int priority(char op) {
    if (op == '(' || op == ')') {
        return 0;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == 'x' || op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

void push(struct Stack* st, int v) {
    if (st -> top == (st -> n) - 1) {
        printf("Stack is full.\n"); 
    }
    else {
        st -> top += 1;
        st -> arr[st -> top] = v;
    }
}

char pop(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n"); 
    }
    else {
        char x = (st -> arr[st -> top]);
        st -> top -= 1; 
        return x;
    }
}

void display(struct Stack* st) {
    if (st -> top == -1) {
        printf("Stack is empty.\n");
    }
    else {
        printf("Stack Values : <top to bottom> \n"); 
        for (int i = st -> top; i >= 0; i--) {
            printf("%c ", st -> arr[i]);
        }
        printf("\n"); 
    }
}

// a+b-(c*d)