#include <stdio.h>

void main() {
    int row, col, i, j;
    printf("How many rows do you want? ");
    scanf("%d", &row);
    printf("How many columns do you want? ");
    scanf(" %d", &col);
    int array[row][col], newarray[col][row];
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) {
            printf("Enter Value for [%d][%d]: ", i,j);
            scanf(" %d", &array[i][j]);
        }
    }
    printf("Before Transpose: \n");
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("After Transpose: \n");
    for (i=0;i<col;i++) {
        for (j=0;j<row;j++) {
            newarray[i][j] = array[j][i];
            printf("%d ", newarray[i][j]);
        }
        printf("\n");
    }
}