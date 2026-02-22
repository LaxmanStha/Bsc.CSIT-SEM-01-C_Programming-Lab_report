#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};


int main() {
    struct Student students[10];
    int i, passCount = 0, failCount = 0;
    
    for (i = 0; i < 10; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        
       
    }
    
    for (i = 0; i < 10; i++) {
        if (students[i].marks >= 40) {
            passCount++;
        } else {
            failCount++;
        }
    }
    
    printf("\nTotal students passed: %d\n", passCount);
    printf("Total students failed: %d\n", failCount);
    
    return 0;
}
