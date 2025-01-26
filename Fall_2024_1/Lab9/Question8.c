#include <stdio.h>

void main() {
    int num1,num2, answer = 0;
    char choice;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    answer = mathfunction(num1,num2);
    printf("The final answer is %d", answer);
}

int mathfunction(num1,num2) {
    char choice;
    int answer = 0;
    printf("Enter the operation you want to perform: ");
    scanf(" %c", &choice);
    switch (choice)
    {
    case '+':
        answer = num1 + num2;
        return answer;
        break;
    case '-':
        answer = num1 - num2;
        return answer;
        break;
    case '*':
        answer = num1 * num2;
        return answer;
        break;
    case '/':
        answer = num1 / num2;
        return answer;
        break;
    default:
        printf("Invalid choice");
        break;
    }
}