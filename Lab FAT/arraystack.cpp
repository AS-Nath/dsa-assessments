#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int n; 
    int top; 
    vector<int> arr; 
    Stack(int n) {
        this -> top = -1; 
        this -> n = n; 
        arr.resize(n); 
    }
    void push(int x) {
        if (top == n - 1) {
            cout << "Stack Overflow!" << endl; 
            return; 
        }
        top += 1; 
        arr[top] = x; 
        cout << "Pushed " << x << " to stack!" << endl; 
    }
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl; 
            return -1; 
        }
        int x = arr[top]; 
        cout << "Popped " << x << " from stack!" << endl; 
        top -= 1;
        return x; 
    }
    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl; 
            return; 
        }
        cout << "Stack Elements (top to bottom) : "; 
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " "; 
        }
        cout << endl; 
    }
}; 

int main(void) {

}