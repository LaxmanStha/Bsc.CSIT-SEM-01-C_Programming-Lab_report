#include <stdio.h>

int main() {
    int num1, num2;
    char op;
    
    printf("Enter two numbers and an operator (+, -, *, /, %%): ");
    scanf("%d %d %c", &num1, &num2, &op);
    
    switch(op) {
        case '+':
            printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("Result: %d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("Result: %d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Result: %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                printf("Result: %d %% %d = %d\n", num1, num2, num1 % num2);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }
    
    return 0;
}
