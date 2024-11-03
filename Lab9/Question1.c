#include <stdio.h>

int product(num1,num2);
void main() {
    int result;
    result = product(4,5);
    printf("%d", result);
}

int product(num1,num2) {
    int prod = 0;
    prod = num1 * num2;
    return prod;
}