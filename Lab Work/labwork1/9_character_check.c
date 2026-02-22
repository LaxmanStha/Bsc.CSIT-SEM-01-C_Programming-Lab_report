#include <stdio.h>

int main() {
    char ch;
    
    printf("Enter a character: ");
    scanf(" %c", &ch);
    
    if (ch >= '0' && ch <= '9') {
        printf("Alpha Digit\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("Alpha lower case character\n");
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("Alpha Uppercase character\n");
    } else {
        printf("Special character\n");
    }
    
    return 0;
}
