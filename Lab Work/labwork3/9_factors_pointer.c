/*
 * Lab 3 - Question 9
 * WAP to calculate the factor of given number using a pointer.
 */

#include <stdio.h>

// Function to print factors of a number using pointer
void printFactors(int *num) {
    printf("Factors of %d are: ", *num);
    
    for (int i = 1; i <= *num; i++) {
        if (*num % i == 0) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

int main() {
    int number;

    // Input number from user
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Call function with pointer to number
    printFactors(&number);

    return 0;
}