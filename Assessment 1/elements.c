#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter Array Size : ");
    scanf("%d", &n); 
    int* arr = (int *)calloc(n, sizeof(int)); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array Elements : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}