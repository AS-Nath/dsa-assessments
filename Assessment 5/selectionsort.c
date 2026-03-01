#include <stdio.h>
#include <stdlib.h>

void selectionsort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int min = i; 
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t; 
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int *)malloc(n * sizeof(int));  
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i); 
    }
    selectionsort(arr, n);
    printf("Sorted : "); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
    return 0;
}