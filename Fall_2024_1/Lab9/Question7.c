#include <stdio.h>
#include <math.h>

void main() {
    int input;
    printf("Enter a number to check if its prime: ");
    scanf("%d", &input);
    prime(input);
}

int prime(num) {
    char isPrime = 'T';
    if (num == 1) {
        isPrime = 'F';
    }
    if (num == 2) {
        isPrime = 'T';
    }
    for (int i=3;i<sqrt(num); i += 2) {
        if (num % i == 0) {
            isPrime = 'F';
        }
    }
    if (isPrime == 'T') {
        printf("Number is not prime.");
    } else {
        printf("Number is prime.");
    }
}