#include <stdio.h>

int main() {
    int a, b, c, middle;
    
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if ((a > b && a < c) || (a < b && a > c)) {
        middle = a;
    } else if ((b > a && b < c) || (b < a && b > c)) {
        middle = b;
    } else {
        middle = c;
    }
    
    printf("Middle number: %d\n", middle);
    
    return 0;
}
