#include <stdio.h>

void main() {
    int num;
    printf("Enter an odd number: ");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("Not an odd number.");
    } else {
        for (int i= num; i>0;i -=2) {
            printf("%d ", i);
        }
    }
}