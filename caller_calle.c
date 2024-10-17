#include<stdio.h>
#include<stdlib.h>

int *allocate_array(int size) {
    int *arr = malloc(size * sizeof(int));
    return arr;
}

int main() {
    int *arr = allocate_array(10);
    // Free allocated memory
    free(arr);  
    return 0;
}

