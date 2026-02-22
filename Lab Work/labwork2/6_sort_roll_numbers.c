#include <stdio.h>

int main() {
    int roll[10], i, j, temp;
    
    printf("Enter 10 roll numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &roll[i]);
    }
    
    // Bubble sort
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (roll[j] > roll[j + 1]) {
                temp = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted roll numbers in ascending order: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", roll[i]);
    }
    printf("\n");
    
    return 0;
}
