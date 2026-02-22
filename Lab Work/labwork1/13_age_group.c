#include <stdio.h>

int main() {
    int age;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age >= 0 && age <= 5) {
        printf("Child\n");
    } else if (age >= 6 && age <= 12) {
        printf("Young\n");
    } else if (age >= 13 && age <= 19) {
        printf("Teen\n");
    } else if (age >= 20 && age <= 40) {
        printf("Adult\n");
    } else if (age > 40) {
        printf("Old\n");
    } else {
        printf("Invalid age\n");
    }
    
    return 0;
}
