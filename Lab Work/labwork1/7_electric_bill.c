#include <stdio.h>

int main() {
    int units;
    float bill = 0.0;
    
    printf("Enter number of units consumed: ");
    scanf("%d", &units);
    
    if (units <= 100) {
        bill = units * 1.50;
    } else if (units <= 200) {
        bill = 100 * 1.50 + (units - 100) * 2.50;
    } else if (units <= 500) {
        bill = 100 * 1.50 + 100 * 2.50 + (units - 200) * 3.50;
    } else {
        bill = 100 * 1.50 + 100 * 2.50 + 300 * 3.50 + (units - 500) * 5.50;
    }
    
    printf("Electric Bill: Rs. %.2f\n", bill);
    
    return 0;
}
