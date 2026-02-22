/*
 * Lab 3 - Question 11
 * WAP to sort to numbers in descending order using a pointer.
 */

#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort two numbers in descending order using pointers
void sortDescending(int *num1, int *num2) {
    if (*num1 < *num2) {
        swap(num1, num2);
    }
}

int main() {
    int number1, number2;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &number1);
    printf("Enter second number: ");
    scanf("%d", &number2);

    // Print numbers before sorting
    printf("\nBefore sorting: %d, %d\n", number1, number2);

    // Sort numbers in descending order
    sortDescending(&number1, &number2);

    // Print numbers after sorting
    printf("After sorting (descending): %d, %d\n", number1, number2);

    return 0;
}