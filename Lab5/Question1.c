#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age < 13) {
        printf("Child");
    }
    else if (age < 18) {
        printf("Teenager");
    }
    else if (age < 60) {
        printf("Adult");
    }
    else {
        printf("Senior");
    }
}