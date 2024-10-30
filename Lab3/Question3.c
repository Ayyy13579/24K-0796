#include <stdio.h>

int main()
{
    float taxrate, salary;
    printf("Enter current tax rate: ");
    scanf("%f",&taxrate);
    printf("Enter current salary: ");
    scanf("%f",&salary);
    salary = salary * (1 - taxrate/100);
    printf("New salary is %f", salary);

}