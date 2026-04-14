#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int n; 
    int top; 
    vector<char> arr; 
    Stack(int n) {
        this -> top = -1; 
        this -> n = n; 
        arr.resize(n); 
    }
    void push(char x) {
        if (top == n - 1) {
            return; 
        }
        top += 1; 
        arr[top] = x; 
    }
    char pop() {
        if (top == -1) {
            return -1; 
        }
        char x = arr[top]; 
        top -= 1;
        return x; 
    }
    char peek() {
        if (top == -1) {
            return -1; 
        }
        return arr[top]; 
    }
}; 

int priority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1; 
    }
    return 0; 
}

int main(void) {
    string s;
    cin >> s; 
    Stack stack{100}; 
    for (int i = 0; i < s.size(); i++) {
        if (isalnum(s[i])) {
            cout << s[i]; 
            continue; 
        }
        char x; 
        if (s[i] == ')') {
            while ((x = stack.pop()) != '(') {
                cout << x; 
            }
            continue; 
        }
        while (stack.top != -1 && priority(s[i]) <= priority(stack.peek())) {
            cout << stack.pop(); 
        }
        stack.push(s[i]); 
    }
    while (stack.top > -1) {
        cout << stack.pop(); 
    }
    cout << endl; 
    return 0; 
}