#include <stdio.h>

int main() {
    int number, digit, evenCount = 0, oddCount = 0;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    number = abs(number); // Handle negative numbers
    
    if (number == 0) {
        evenCount = 1;
    }
    
    while (number > 0) {
        digit = number % 10;
        if (digit % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        number /= 10;
    }
    
    printf("Even digits: %d\n", evenCount);
    printf("Odd digits: %d\n", oddCount);
    
    return 0;
}
