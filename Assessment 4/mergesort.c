#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void sort (int* arr, int n, int l, int r);
void merge(int* arr1, int l1, int* arr2, int l2);

int main(void) {
    int n;
    scanf("%d", &n); 
    int* arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr, n, 0, n - 1); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int* arr1, int l1, int* arr2, int l2) {
    int c1 = 0;
    int c2 = 0;
    int c = 0;
    int* merged = (int *)calloc(l1 + l2, sizeof(int)); 
    while (c < l1 + l2 && c1 < l1 && c2 < l2) {
        if (*(arr1 + c1) < *(arr2 + c2)) {
            merged[c] = *(arr1 + c1);
            c1 += 1;
            c += 1;
        }
        else {
            merged[c] = *(arr2 + c2);
            c2 += 1;
            c += 1;
        }
    }
    while (c < l1 + l2 && c1 < l1) {
        merged[c] = *(arr1 + c1); 
        c1 += 1;
        c += 1;
    }
    while (c < l1 + l2 && c2 < l2) {
        merged[c] = *(arr2 + c2); 
        c2 += 1;
        c += 1;
    }
    for (int i = 0; i < l1 + l2; i++) {
        *(arr1 + i) = merged[i]; 
    }
    free(merged); 
}

void sort(int* arr, int n, int l, int r) {
    if (l >= r) {
        return; 
    }
    else {
        int mid = l + (r - l) / 2; 
        sort(arr, n, l, mid); 
        sort(arr, n, mid+1, r); 
        merge(arr + l, mid - l + 1, arr + mid + 1, r - mid); 
    }
}


