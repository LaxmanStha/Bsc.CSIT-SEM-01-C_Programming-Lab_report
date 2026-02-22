/*
 * Lab 3 - Question 6
 * WAP in C to accept a number and print its value and address using a pointer.
 */

#include <stdio.h>

int main() {
    int num;
    int *ptr; // Pointer to int

    // Input number from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Assign address of num to pointer
    ptr = &num;

    // Print value and address using pointer
    printf("\nValue of num: %d\n", num);
    printf("Value using pointer: %d\n", *ptr);
    printf("Address of num: %p\n", &num);
    printf("Address stored in pointer: %p\n", ptr);

    return 0;
}