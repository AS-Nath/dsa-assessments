#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int search(int* arr, int l, int r, int target) {
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) {
        return mid; 
    }
    else if (arr[mid] < target) {
        return search(arr, mid + 1, r, target);
    }
    else {
        return search(arr, l, mid - 1, target);
    }
}

int comp(const void* a, const void* b) { // for qsort()
    if (*((int *)a) - *((int *)b) > 0) {
        return 1;
    }
    else if (*((int *)a) - *((int *)b) == 0) {
        return 0;
    }
    else {
        return -1; 
    }
}

int main(void) {
    int n;
    printf("Enter 'n' and then the array elements\n"); 
    scanf("%d", &n);
    int* arr = (int *)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i); 
    }
    printf("Enter the value to search : \n");
    int target;
    scanf("%d", &target); 
    // User can enter in any order, the program will sort it. 
    qsort(arr, n, sizeof(int), comp);
    int v = search(arr, 0, n - 1, target);
    if (v > 0) {
        printf("Found at index %d!\n", v);
    }   
    else {
        printf("Not Found!\n"); 
    }
    return 0; 
}