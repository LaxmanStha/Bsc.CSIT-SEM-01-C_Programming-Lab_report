#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char address[100];
    int roll;
};

int main() {
    struct Student s;
    
    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline
    
    printf("Enter address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0'; // Remove newline
    
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    
    printf("\nStudent Record:\n");
    printf("Name: %s\n", s.name);
    printf("Address: %s\n", s.address);
    printf("Roll Number: %d\n", s.roll);
    
    return 0;
}
