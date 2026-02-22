#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char address[100];
    int pin;
    char phone[15];
};

int main() {
    struct Employee emp;
    
    printf("Enter employee details:\n");
    
    printf("Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';
    
    printf("Address: ");
    fgets(emp.address, sizeof(emp.address), stdin);
    emp.address[strcspn(emp.address, "\n")] = '\0';
    
    printf("PIN: ");
    scanf("%d", &emp.pin);
    
    printf("Phone: ");
    scanf("%s", emp.phone);
    
    // Check if address contains "Banepa"
    if (strstr(emp.address, "Banepa") != NULL) {
        printf("\nEmployee from Banepa:\n");
        printf("Name: %s\n", emp.name);
        printf("Address: %s\n", emp.address);
        printf("PIN: %d\n", emp.pin);
        printf("Phone: %s\n", emp.phone);
    } else {
        printf("\nEmployee not from Banepa\n");
    }
    
    return 0;
}
