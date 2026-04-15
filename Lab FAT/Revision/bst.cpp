#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right; 
    Node(int x) : data{x}, left{nullptr}, right{nullptr} {} 
};

struct BST {
    Node* root; 
    BST() : root{nullptr} {}
    void insert(Node*& copy, int x) {
        if (copy == nullptr) {
            copy = new Node(x);
            return; 
        }
        if (x < copy -> data) {
            if (copy -> left == nullptr) {
                copy -> left = new Node(x); 
                return; 
            }
            insert(copy -> left, x); 
        }
        else {
            if (copy -> right == nullptr) {
                copy -> right = new Node(x); 
                return; 
            }
            insert(copy -> right, x); 
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
    Node* max(Node* copy) {
        if (copy == nullptr) {
            return nullptr;
        }
        if (copy -> right == nullptr) {
            return copy; 
        }
        return max(copy -> right); 
    }
    void remove(Node*& copy, int x) {
        if (copy == nullptr) { 
            return; 
        }
        if (copy -> data == x) {
            if (copy -> left == nullptr && copy -> right == nullptr) {
                delete copy;
                copy = nullptr;  
            }
            else if (copy -> left == nullptr || copy -> right == nullptr) {
                Node* delNode = copy; 
                copy = (copy -> right == nullptr) ? copy -> left : copy -> right; 
                delete delNode;  
                delNode = nullptr; 
            }
            else {
                Node* replacement = max(copy -> left); 
                copy -> data = replacement -> data; 
                remove(copy -> left, replacement -> data); 
            }
        }
        else if (x < copy -> data) {
            remove(copy -> left, x); 
        }
        else {
            remove(copy -> right, x); 
        }
    }
};

int main(void) {
    BST bst;
    bst.insert(bst.root, 3); 
    bst.insert(bst.root, 2); 
    bst.insert(bst.root, 4); 
    bst.insert(bst.root, 1); 
    bst.insert(bst.root, 5);
    bst.remove(bst.root, 4); 
    bst.preorder(bst.root); 
    bst.inorder(bst.root);
    bst.postorder(bst.root);
    cout << endl; 
    return 0;   
}