#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data{x}, next{nullptr} {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head{nullptr} {}
    void insert(int x, int position) {
        Node* newNode = new Node(x); 
        if (head == nullptr) {
            head = newNode;
            cout << "Added " << x << " to linked list!\n"; 
            return; 
        }
        if (position == 1) {
            newNode -> next = head;
            head = head -> next;
            head = newNode; 
            cout << "Added " << x << " to linked list!\n"; 
            return; 
        }
        Node* travNode = head;
        int c = 1; 
        while (travNode != nullptr && c < position - 1) {
            c += 1;
            travNode = travNode -> next;
        }
        newNode -> next = travNode -> next;
        travNode -> next = newNode; 
        cout << "Added " << x << " to linked list!\n"; 
        return; 
    }
    void remove(int position) {
        if (head == nullptr) {
            cout << "Linked List is empty!\n"; 
            return; 
        }
        if (position == 1) {
            Node* delNode = head;
            head = head -> next; 
            cout << "Deleted " << delNode -> data << " from linked list!\n"; 
            delete delNode; 
            return; 
        }
        int c = 1;
        Node* travNode = head;
        while (travNode != nullptr && c < position - 1) {
            c += 1;
            travNode = travNode -> next;
        }
        Node* delNode = travNode -> next;
        travNode -> next = delNode -> next;
        cout << "Deleted " << delNode -> data << " from linked list!\n";
        delete delNode; 
    }
    void reverse() {
        if (head == nullptr) {
            cout << "Linked List is empty.\n"; 
            return; 
        }
        if (head -> next == nullptr) {
            return; // Reverses to itself.    
        }
        Node* prev = nullptr; 
        Node* current = head;
        Node* next = head -> next; 
        while (current != nullptr) {
            current -> next = prev; 
            prev = current; 
            current = next;
            next = (next == nullptr) ? next : next -> next; 
        }
        head = prev; 
    }
    void display() { 
        if (head == nullptr) {
            cout << "Linked List is empty!" << endl; 
            return; 
        }
        Node* travNode = head;
        cout << "HEAD "; 
        while (travNode != nullptr) {
            cout << "-> " << travNode -> data << " "; 
            travNode = travNode -> next; 
        } 
        cout << "-> NULL" << endl; 
    }
};

int main(void) {
    LinkedList ll;
    for (int i = 0; i < 5; i++) {
        ll.insert(i + 1, i + 1); 
    }
    ll.display(); 
    ll.reverse();
    ll.display();
    ll.remove(2);
    ll.display(); 
    return 0; 
}