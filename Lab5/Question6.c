#include <stdio.h>

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    (number > 0) ? (printf("Positive")) : (number < 0) ? (printf("Negative")) : (printf("0"));
    
}