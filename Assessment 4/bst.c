#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right; 
}; 

void preorder(struct Node* root) {
    if (root == NULL) {
        return; 
    }
    printf("%d ", root -> data); 
    preorder(root -> left);
    preorder(root -> right); 
}

void postorder(struct Node* root) {
    if (root == NULL) {
        return; 
    }
    postorder(root -> left); 
    postorder(root -> right); 
    printf("%d ", root -> data); 
}

void inorder(struct Node* root) {
    if (root == NULL) {
        return; 
    }
    inorder(root -> left); 
    printf("%d ", root -> data); 
    inorder(root -> right); 
}

void insert(struct Node** head, int v) {
    struct Node* current = *head;
    if (current == NULL) {
        *head = (struct Node *)malloc(sizeof(struct Node)); 
        current = *head;
        current -> data = v;
        current -> left = NULL;
        current -> right = NULL; 
        printf("Inserted %d in BST!\n", v);
        return; 
    }
    int d = current -> data;
    if (v == d) {
        printf("%d already exists in BST.\n", v); 
        return; 
    }
    else if (v < d) {
        if (current -> left != NULL) {
            insert(&(current -> left), v); 
        }
        else {
            current -> left = (struct Node *)malloc(sizeof(struct Node)); 
            current -> left -> data = v; 
            current -> left -> left = NULL; 
            current -> left -> right = NULL;             
            printf("Inserted %d in BST!\n", v);
        }
    }
    else {
        if (current -> right != NULL) {
            insert(&(current -> right), v); 
        }
        else {
            current -> right = (struct Node *)malloc(sizeof(struct Node)); 
            current -> right -> data = v; 
            current -> right -> left = NULL;
            current -> right -> right = NULL;    
            printf("Inserted %d in BST!\n", v); 
        }
    }
}

struct Node* search(struct Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root -> data == val) {
        return root; 
    }
    if (val < root -> data) {
        return search(root -> left, val);
    }
    else {
        return search(root -> right, val); 
    }
}

struct Node* searchparent(struct Node* root, int val) {
    if (root == NULL) {
        return NULL; 
    }
    if ((root -> left != NULL && root -> left -> data == val) || (root -> right != NULL && root -> right -> data == val)) {
        return root; 
    }
    if (val < root -> data) {
        return searchparent(root -> left, val);
    }
    else {
        return searchparent(root -> right, val); 
    }
}

struct Node* min(struct Node** root) {
    struct Node* current = *root;
    if (current -> left != NULL) {
        return min(&(current -> left)); 
    }
    else {
        return current;
    }
}

struct Node* max(struct Node** root) {
    struct Node* current = *root;
    if (current -> right != NULL) {
        return max(&(current -> right)); 
    }
    else {
        return current;
    }
}

int delete(struct Node** root, int val) { 
    if (root == NULL) {
        return -1; 
    }
    struct Node* testNode = *root;
    if (testNode -> data == val) { // Deleting the root is a special case. 
        if (testNode -> left == NULL && testNode -> right == NULL) {
            *root = NULL;
        }
        else if (testNode -> left == NULL || testNode -> right == NULL) {
            *root = (testNode -> left == NULL) ? testNode -> right : testNode -> left; 
            free(testNode); 
        }
        else {
            struct Node* temp = max(&(testNode -> left)); 
            int recoverValue = temp -> data;
            delete(root, recoverValue); 
            testNode -> data = recoverValue;
        }
        return val;
    }
    struct Node* parent = searchparent(*root, val);
    if (parent == NULL) {
        return -1; 
    } 
    struct Node* child = (parent -> left -> data == val) ? parent -> left : parent -> right; 
    bool left = true; 
    if (child == parent -> right) {
        left = false;
    }
    if (child -> left == NULL && child -> right == NULL) {
        free(child); 
        if (left) {
            parent -> left = NULL;
        }
        else {
            parent -> right = NULL; 
        }
    }
    else if (child -> left == NULL || child -> right == NULL) {
        struct Node* temp = (child -> left == NULL) ? child -> right : child -> left; 
        if (left) {
            parent -> left = temp; 
        }
        else {
            parent -> right = temp; 
        }
    }
    else { 
        struct Node* temp = max(&(child -> left)); 
        int recoverValue = temp -> data;
        delete(&child, recoverValue);
        child -> data = recoverValue;
    }
    return val; 
}

int main(void) {
    struct Node* root = NULL; 
    while (true) {
        printf("Enter 1 to insert a node.\n");
        printf("Enter 2 to delete a node.\n"); 
        printf("Enter 3 for a preorder traversal.\n"); 
        printf("Enter 4 for an inorder traversal.\n"); 
        printf("Enter 5 for a postorder traversal.\n"); 
        printf("Enter any other integer to quit.\n");
        int c;
        scanf("%d", &c);
        int v; 
        switch (c) {
            case 1 : 
                printf("Enter value to insert : "); 
                scanf("%d", &v); 
                insert(&root, v); 
                break;
            case 2 : 
                printf("Enter value to delete : "); 
                scanf("%d", &v);
                int t = delete(&root, v); 
                if (t) {
                    printf("Deleted %d from BST!\n", t); 
                }  
                else {
                    printf("Element does not exist in BST.\n"); 
                }
                break;
            case 3 : 
                preorder(root);
                printf("\n");
                break;
            case 4 : 
                inorder(root);
                printf("\n");
                break;
            case 5 : 
                postorder(root); 
                printf("\n"); 
                break;
            default : 
                return 0;
        }
    }
    return 0; 
}