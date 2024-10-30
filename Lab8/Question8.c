#include <stdio.h>

void main() {
    int rows;
    printf("How many rows do you want the top half to be? ");
    scanf("%d", &rows);
    for (int i=1;i<rows+1;i++) {
        for (int j=rows-i;j>0;j--) {
            printf(" ");
        }
        for (int starcount=0;starcount<i;starcount++) {
            printf("**");
        }
        for (int j=rows-i;j>0;j--) {
            printf(" ");
        }
        printf("\n");
    }
    for (int i=1;i<rows;i++) {
        for (int j=1;j<i+1;j++) {
            printf(" ");
        }
        for (int starcount=rows-i;starcount>0;starcount--) {
            printf("**");
        }
        for (int j=1;j<i+1;j++) {
            printf(" ");
        }
        printf("\n");
    }
}