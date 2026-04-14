#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; 
    Node* left;
    Node* right; 
    Node(int n) : data{n}, left{nullptr}, right{nullptr} {}
}; 

struct BST {
    Node* root; 
    BST() : root{nullptr} {} 
    void insert(int n) {
        if (root == nullptr) {
            Node* newNode = new Node(n); 
            root = newNode;
            cout << "Inserted " << n << "!" << endl; 
            return; 
        }
        Node* rootcopy = root; 
        while(true) {
            if (n < rootcopy -> data) {
                if (rootcopy -> left == nullptr) {
                    Node* newNode = new Node(n);
                    rootcopy -> left = newNode; 
                    cout << "Inserted " << n << "!" << endl; 
                    return; 
                }
                rootcopy = rootcopy -> left; 
            }
            else {
                if (rootcopy -> right == nullptr) {
                    Node* newNode = new Node(n);
                    rootcopy -> right = newNode; 
                    cout << "Inserted " << n << "!" << endl; 
                    return; 
                }
                rootcopy = rootcopy -> right; 
            }
        }
    }
    void preorder(Node* copy) {
        if (copy == nullptr) {
            return; 
        }
        cout << copy -> data << " "; 
        preorder(copy -> left); 
        preorder(copy -> right); 
    }
    void inorder(Node* copy) {
        if (copy == nullptr) {
            return; 
        }
        inorder(copy -> left); 
        cout << copy -> data << " "; 
        inorder(copy -> right); 
    }
    void postorder(Node* copy) {
        if (copy == nullptr) {
            return; 
        }
        postorder(copy -> left); 
        postorder(copy -> right); 
        cout << copy -> data << " "; 
    }
    Node* search(Node* copy, int n) { // Remember to search before deleting. 
        if (copy == nullptr) {
            return nullptr;
        }
        if (copy -> data == n) {
            return copy;
        }
        if (n < copy -> data) {
            return search(copy -> left, n); 
        }
        else {
            return search(copy -> right, n); 
        }
    }
    Node* max(Node* copy) {
        if (copy -> right == nullptr) {
            return copy;  
        }
        return max(copy -> right); 
    }
    void remove(Node*& copy, int n) {
        if (copy == nullptr) {
            return; 
        }
        if (n == copy -> data) {
            if (copy -> left == nullptr && copy -> right == nullptr) {  
                delete copy;
                copy = nullptr; 
            }
            else if (copy -> left == nullptr || copy -> right == nullptr) {
                Node* delNode = copy; 
                copy = (copy -> left == nullptr) ? copy -> right : copy -> left; 
                delete delNode; 
                delNode = nullptr; 
            }
            else {
                Node* replacement = max(copy -> left); 
                copy -> data = replacement -> data; 
                remove(copy -> left, replacement -> data); 
            }
            cout << "Reached" << endl; 
            return; 
        }
        else if (n < copy -> data) {
            remove(copy -> left, n);
            return; 
        }
        else {
            remove(copy -> right, n); 
            return; 
        }
    }
};

int main(void) {
    BST bst;
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(1);
    bst.insert(5); 
    bst.remove(bst.root, 3); 
    bst.preorder(bst.root); 
    cout << endl;
    bst.inorder(bst.root);
    cout << endl; 
    bst.postorder(bst.root);
    cout << endl; 
    return 0; 
}