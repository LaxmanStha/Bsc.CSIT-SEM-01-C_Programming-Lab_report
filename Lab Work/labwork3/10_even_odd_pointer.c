/*
 * Lab 3 - Question 10
 * WAP to check whether a number is even or odd using pointers.
 */

#include <stdio.h>

// Function to check even or odd using pointer
void checkEvenOdd(int *num) {
    if (*num % 2 == 0) {
        printf("%d is even.\n", *num);
    } else {
        printf("%d is odd.\n", *num);
    }
}

int main() {
    int number;

    // Input number from user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Call function with pointer
    checkEvenOdd(&number);

    return 0;
}