#include <stdio.h>

void main() {
    int i,j,k = 0,row,columnsaddle, array[3][3] = {{2,4,3},{5,6,7},{1,2,3}};
    char found = 'F';
    while (found == 'F' && k < 3) {
        char found = 'T';
        int rowsaddle = 1000;
        for (i=0;i<3;i++) {
            if (array[k][i] < rowsaddle) {
            rowsaddle = array[k][i];
            columnsaddle = i;
            }
        }
        for (j=0;j<3;j++) {
            if (array[j][columnsaddle] > rowsaddle) {
                found = 'F';
                break;
            }
        }
        if (found == 'F') {
            k++;
        }
    }
    if (found == 'T') {
        printf("The saddle point is at [%d,%d]", k,columnsaddle);
    } else {
        printf("No saddle point found.");
    }
}