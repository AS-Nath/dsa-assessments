#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int l, int r) {
    int pivot = arr[r]; 
    int part_index = l;
    for (int i = l; i < r; i++) {
        if (arr[i] <= pivot) {
            int t = arr[i];
            arr[i] = arr[part_index];
            arr[part_index] = t;
            part_index += 1;
        }
    }
    arr[r] = arr[part_index];
    arr[part_index] = pivot; 
    return part_index;
}

void quicksort(int* arr, int l, int r) {
    if (l < r) {
        int part_index = partition(arr, l, r); 
        quicksort(arr, l, part_index - 1); 
        quicksort(arr, part_index + 1, r); 
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
    quicksort(arr, 0, n - 1); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
    return 0; 
}