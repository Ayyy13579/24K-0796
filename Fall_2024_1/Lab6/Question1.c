#include <stdio.h>

int main() {
    int sum,number;
    do {
        printf("Enter a number: ");
        scanf("%d", &number);
        sum = sum + number;
    } while (number != 0);
    
    printf("The sum is %d", sum);
}