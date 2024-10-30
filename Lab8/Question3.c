#include <stdio.h>

void main() {
    int array[2][3][3] = {{{1,2,3},{4,5,6},{7,8,9}},{{3,5,7},{11,56,34},{6,9,20}}}, sum = 0;
    for (int i=0;i<2;i++) {
        for (int j=0;j<3;j++) {
            for (int k=0;k<3;k++) {
                printf("%d ", array[i][j][k]);
                sum += array[i][j][k];
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Sum of all elements is: %d", sum);
}