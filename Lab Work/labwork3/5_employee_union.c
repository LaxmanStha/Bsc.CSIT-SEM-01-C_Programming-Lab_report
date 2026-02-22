/*
 * Lab 3 - Question 5
 * WAP to store the record of n numbers employees using union.
 */

#include <stdio.h>
#include <string.h>

// Union to store different types of employee data
union EmployeeData {
    int employeeId;
    float salary;
    char department[50];
};

// Structure to store employee record with union
struct Employee {
    char name[100];
    int age;
    union EmployeeData data;
    int dataType; // 1 for ID, 2 for salary, 3 for department
};

int main() {
    int n;

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Create array of employees
    struct Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        
        printf("Enter name: ");
        scanf(" %[^\n]", employees[i].name);
        
        printf("Enter age: ");
        scanf("%d", &employees[i].age);
        
        printf("Enter data type (1 for ID, 2 for salary, 3 for department): ");
        scanf("%d", &employees[i].dataType);
        
        switch (employees[i].dataType) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &employees[i].data.employeeId);
                break;
            case 2:
                printf("Enter salary: ");
                scanf("%f", &employees[i].data.salary);
                break;
            case 3:
                printf("Enter department: ");
                scanf(" %[^\n]", employees[i].data.department);
                break;
            default:
                printf("Invalid data type. Using ID as default.\n");
                employees[i].dataType = 1;
                employees[i].data.employeeId = 0;
        }
    }

    // Display employee records
    printf("\nEmployee Records:\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Age: %d\n", employees[i].age);
        
        switch (employees[i].dataType) {
            case 1:
                printf("Employee ID: %d\n", employees[i].data.employeeId);
                break;
            case 2:
                printf("Salary: %.2f\n", employees[i].data.salary);
                break;
            case 3:
                printf("Department: %s\n", employees[i].data.department);
                break;
        }
    }

    return 0;
}