#include <stdio.h>

int main() {
    int number, isPrime,i;
    printf("Enter number: ");
    scanf("%d", &number);
    if (number/10 == 0) {
        printf("One digit number\n");
    } else {
        printf("Multiple digit number\n");
    } 
    for (i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            isPrime = 1;
            break;
        }
    }
    if (isPrime == 0) {
        printf("Prime");
    }
    else {
        printf("Composite");
    }
}
