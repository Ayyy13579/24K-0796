#include <stdio.h>

int main() {
    int age;
    float income, credit;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your income: ");
    scanf(" %f", &income);
    printf("Enter credit score: ");
    scanf(" %f", &credit);
    if (age > 18) {
        if (income < 50,000 && credit > 80) {
            printf("Eligible for loan");
        }
        else {
            printf("Not eligible");
        }
    }
    else {
        printf("You are underage");
    }
}