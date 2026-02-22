#include <stdio.h>

#define PI 3.14

int main() {
    float radius, area, volume;
    
    printf("Enter radius of sphere: ");
    scanf("%f", &radius);
    
    area = 4 * PI * radius * radius;
    volume = (4 / 3) * PI * radius * radius * radius;
    
    printf("Area of sphere: %.2f", area);
    printf("Volume of sphere: %.2f\n", volume);
    
    return 0;
}
