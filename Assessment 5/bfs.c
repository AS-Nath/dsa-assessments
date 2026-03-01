#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjNode {
    int dest; // Value of the next vertex 
    struct AdjNode* next; // Linked list of successive nodes 
} AdjNode; 

typedef struct Graph {
    int V; // Number of vertices 
    int capacity; // Number of AdjNode* memory locations allocated to array.  
    AdjNode** array; // Array of adjacency (linked) lists 
} Graph; 

AdjNode* newAdjNode(int dest) {
    AdjNode* temp = (AdjNode *)malloc(sizeof(AdjNode)); 
    temp -> dest = dest; 
    temp -> next = NULL; 
    return temp; 
}

void addEdge(Graph* graph, int source, int dest) {
    if (graph -> array == NULL) {
        graph -> array = (AdjNode **)malloc((((source > dest) ? source : dest) + 1) * sizeof(AdjNode *)); 
        for (int i = 0; i < ((source > dest) ? source : dest) + 1; i++) {
            graph -> array[i] = NULL; 
        }
        graph -> capacity = ((source > dest) ? source : dest) + 1;
    }
    if (source >= graph -> capacity || dest >= graph -> capacity) {
        graph -> array = realloc(graph -> array, (((source > dest) ? source : dest) + 1) * sizeof(AdjNode *)); 
        for (int i = graph -> capacity; i < ((source > dest) ? source : dest) + 1; i++) {
            graph -> array[i] = NULL; 
        }
        graph -> capacity = ((source > dest) ? source : dest) + 1; 
    }
    if (graph -> array[source] == NULL) {
        graph -> V += 1;
    }
    if (graph -> array[dest] == NULL) {
        graph -> V += 1; 
    }
    AdjNode* destNode = newAdjNode(dest); 
    destNode -> next = graph -> array[source];
    graph -> array[source] = destNode; 
    AdjNode* sourceNode = newAdjNode(source); 
    sourceNode -> next = graph -> array[dest]; 
    graph -> array[dest] = sourceNode; 
}

Graph* createGraph() {
    Graph* newGraph = (Graph *)malloc(sizeof(Graph)); 
    newGraph -> V = 0;
    newGraph -> capacity = 0;
    newGraph -> array = NULL; 
    return newGraph; 
}

struct Node {
    int data;
    struct Node* next; 
}; 

int pop(struct Node** head, int position) {
    struct Node* travNode = *head;
    if (*head == NULL) {
        return -1;
    }
    else if (position == 1) {
        struct Node* newhead = travNode -> next; 
        *head = newhead;
        int x = travNode -> data; 
        free(travNode);
        return x;
    }
    else {
        int c = 1; 
        while (travNode -> next != NULL && c != position - 1) {
            travNode = travNode -> next;
            c += 1;
        }
        if (travNode -> next == NULL) {
            return -1;
        }
        else {
            struct Node* delNode = travNode -> next; 
            int v = delNode -> data;
            travNode -> next = delNode -> next; 
            int x = delNode -> data;
            free(delNode);
            return x; 
        }
    }
}

void push(struct Node** head, int n, int position) {
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node)); 
    newnode -> data = n;
    if (*head == NULL) {
        newnode -> next = NULL; 
        *head = newnode; 
    }
    else if (position == 1) {
        newnode -> next = *head;
        *head = newnode; 
    }
    else {
        int c = 1;
        struct Node* travNode = *head;  
        while (travNode -> next != NULL && c != position - 1) {
            travNode = travNode -> next; 
            c += 1; 
        }
        newnode -> next = travNode -> next; 
        travNode -> next = newnode; 
    }
}

void bfs(Graph* graph) {
    if (graph == NULL || graph->array == NULL) {
        return;    }

    bool* visited = calloc(graph->capacity, sizeof(bool));
    struct Node* queue = NULL;
    for (int i = 0; i < graph->capacity; i++) {
        if (graph->array[i] != NULL && !visited[i]) {
            push(&queue, i, 1000000); 
            visited[i] = true;
            while (queue != NULL) {
                int v = pop(&queue, 1); 
                printf("%d ", v);
                AdjNode* temp = graph->array[v];
                while (temp != NULL) {
                    if (!visited[temp->dest]) {
                        push(&queue, temp->dest, 1000000); 
                        visited[temp->dest] = true;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    free(visited);
}

int main(void) {
    Graph* g = createGraph();
    int c;
    int src, dest;
    while (true) {
        printf("Enter 1 to add edge\n");
        printf("Enter 2 to run BFS\n");
        printf("Enter any other integer to exit\n");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);
                if (src == dest) {
                    printf("Self-loops are not allowed in this model.\n");
                } 
                else {
                    addEdge(g, src, dest);
                    printf("Edge added between %d and %d\n", src, dest);
                }
                break;
            case 2:
                if (g->array == NULL) {
                    printf("Graph is empty.\n");
                } 
                else {
                    printf("BFS Traversal:\n");
                    bfs(g);
                    printf("\n");
                }
                break;

            default:
                return 0;
        }
    }
}