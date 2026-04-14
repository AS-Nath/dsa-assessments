#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int n; 
    int front;
    int rear;
    vector<int> arr;
    Queue(int n) : n{n}, front{-1}, rear{-1} {
        arr.resize(n); 
    }
    void push(int x){
        if (front == (rear + 1) % n) {
            cout << "Queue full!" << endl;
            return; 
        }
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear = (rear + 1) % n; 
        arr[rear] = x; 
        cout << "Pushed " << x << " to queue!" << endl; 
    }
    int pop() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        int x = arr[front];
        if (front == rear) { 
            front = -1;
            rear = -1; 
        }
        else if (front == n - 1) {
            front = 0; 
        }
        else { 
            front += 1; 
        }
        cout << "Popped " << x << " from queue!" << endl; 
        return x; 
    }
    void display() {
        if (front == -1 && rear == -1) {
            cout << "Queue is empty!" << endl; 
            return; 
        }
        cout << "Queue Elements (front to back) : ";
        int c = front;
        while (true) {
            cout << arr[c] << " ";
            if (c == rear) {
                break; 
            }
            c = (c + 1) % n; 
        }
        cout << endl; 
    }
};

int main(void) {

}