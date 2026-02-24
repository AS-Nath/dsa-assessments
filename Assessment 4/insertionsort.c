#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int *)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i); 
    }
    // assume index 0 is sorted. 
    for (int i = 1; i < n; i++) {
        int e = arr[i];
        int c = i;
        while (c > 0 && e < arr[c - 1]) {
            arr[c] = arr[c - 1]; 
            c -= 1;
        }
        arr[c] = e; 
    }
    printf("Sorted : "); 
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
    return 0;
}