#include <stdio.h>

int main() {
    int age;
    char citizen;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Are you a citizen? Y/N: ");
    scanf(" %c", &citizen);
    if (age > 18 && citizen == 'Y' || citizen == 'y') {
        printf("Eligible to vote!");
    }
    else {
        printf("Not eligible");
    }
}