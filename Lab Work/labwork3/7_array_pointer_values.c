/*
 * Lab 3 - Question 7
 * WAP to print values and addresses of 5 elements stored in an array using a pointer.
 */

#include <stdio.h>

#define ARRAY_SIZE 5

int main() {
    int arr[ARRAY_SIZE];
    int *ptr;

    // Input 5 elements into the array
    printf("Enter %d integers:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Point pointer to first element of array
    ptr = arr; // or &arr[0]

    // Print values and addresses using pointer
    printf("\nArray Elements:\n");
    printf("Index\tValue\tAddress\n");
    printf("------------------------------\n");
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\t%d\t%p\n", i, *(ptr + i), (ptr + i));
    }

    return 0;
}