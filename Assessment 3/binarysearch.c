#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int* arr, int l, int r, int target) {
    if (l >= r) {
        if (arr[l] == target) {
            return true;
        }
        return false;
    }
    int mid = l + (l - r) / 2;
    if (arr[mid] < target) {
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
    if (search(arr, 0, n - 1, target)) {
        printf("Found!\n");
    }   
    else {
        printf("Not Found!\n"); 
    }
    return 0; 
}