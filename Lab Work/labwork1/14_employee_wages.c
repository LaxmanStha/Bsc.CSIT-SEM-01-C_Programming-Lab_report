#include <stdio.h>

int main() {
    float hours, wages;
    
    printf("Enter working hours: ");
    scanf("%f", &hours);
    
    if (hours <= 8) {
        wages = hours * 100;
    } else {
        wages = 8 * 100 + (hours - 8) * 120;
    }
    
    printf("Total wages: Rs. %.2f\n", wages);
    
    return 0;
}
