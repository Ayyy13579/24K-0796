#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    int** array = (int **)malloc(m * sizeof(int*));
    if (array == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    for (int i=0; i < m; i++) {
        array[i] = (int *)malloc(n * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed.");
        }
    }
    for (int i=0; i< m; i++) {
        for (int j = 0; j <n; j++) {
            printf("Enter value for [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    for (int i=0; i< m; i++) {
        for (int j = 0; j <n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}