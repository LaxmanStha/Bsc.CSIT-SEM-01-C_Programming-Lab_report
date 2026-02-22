#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("Hailstone series: ");
    
    while (number != 1) {
        printf("%d ", number);
        
        if (number % 2 == 0) {
            number /= 2;
        } else {
            number = 3 * number + 1;
        }
    }
    
    printf("1\n");
    return 0;
}
