#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next; 
    Node(int n) : data{n}, next{nullptr} {} 
};

struct Stack {
    Node* head;
    Stack() : head{nullptr} {} 
    void push(int n) {
        if (head == nullptr) {
            Node* newNode = new Node(n); 
            head = newNode;
            return; 
        }
        Node* newNode = new Node(n); 
        newNode -> next = head;
        head = newNode; 
        cout << "Pushed " << n << " to stack!\n"; 
    }
    int pop() {
        if (head == NULL) {
            cout << "Stack is empty!" << endl; 
            return -1; 
        }
        Node* delNode = head;
        head = head -> next;
        int x = delNode -> data;
        cout << "Deleted " << x << " from stack!\n"; 
        delete delNode; 
        return x;
    }
    void display() {
        if (head == NULL) {
            cout << "Stack is empty!" << endl; 
            return; 
        }
        Node* travNode = head;
        cout << "Stack (top-to-bottom) : "; 
        while (travNode != NULL) {
            cout << travNode -> data << " "; 
            travNode = travNode -> next;
        }
        cout << endl; 
    }
};

int main(void) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0; 
}