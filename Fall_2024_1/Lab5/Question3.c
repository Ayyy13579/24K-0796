#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number%3 == 0 && number%5 == 0) {
        printf("Divisible by both 3 and 5");
    }
    else {
        printf("Not divisible");
    }
}