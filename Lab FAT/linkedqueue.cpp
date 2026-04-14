#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next; 
    Node(int n) : data{n}, next{nullptr} {} 
};

struct Queue {
    Node* head; 
    Queue() : head{nullptr} {} 
    void push(int n) {
        if (head == nullptr) {
            Node* newNode = new Node(n);
            head = newNode; 
            cout << "Pushed " << n << " to queue!\n"; 
            return; 
        }
        Node* travNode = head;
        while (travNode -> next != NULL) {
            travNode = travNode -> next;
        }
        Node* newNode = new Node(n); 
        travNode -> next = newNode; 
        cout << "Pushed " << n << " to queue!\n"; 
    }
    int pop() {
        if (head == nullptr) {
            cout << "Queue is empty!\n"; 
            return -1; 
        }
        Node* delNode = head;
        int x = delNode -> data;
        head = head -> next;
        delete delNode; 
        cout << "Popped " << x << " from queue!\n"; 
        return x;
    }
    void display() {
        if (head == nullptr) {
            cout << "Queue is empty!\n"; 
            return; 
        }
        Node* travNode = head;
        cout << "Queue Elements : "; 
        while (travNode != nullptr) {
            cout << travNode -> data << " "; 
            travNode = travNode -> next; 
        }
        cout << endl; 
    }
};

int main(void) {
    Queue q;
    q.push(1); 
    q.push(2); 
    q.push(3); 
    q.push(4); 
    q.push(5);
    q.display();
    q.pop();
    q.pop();
    q.display();
    return 0;  
}