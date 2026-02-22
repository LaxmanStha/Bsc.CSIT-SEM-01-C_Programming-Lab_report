#include <stdio.h>

int main() {
    int matrix[3][2], transpose[2][3];
    int i, j;
    
    printf("Enter elements of 3x2 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Transpose
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    printf("\nTranspose matrix (2x3):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
