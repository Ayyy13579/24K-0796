#include <stdio.h>

void main() {
    swapIntegers();
}

int swapIntegers() {
    int num1, num2, temp;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("Number 1 is %d\n", num1);
    printf("Number 2 is %d\n", num2);
}