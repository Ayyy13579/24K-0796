#include <stdio.h>

int main()
{
    char Name[10];
    char ID[5];
    int Unit;
    float bill, charge;
    printf("Enter your name: ");
    scanf(" %s",&Name);
    printf("Enter your ID: ");
    scanf(" %s",&ID);
    printf("Enter the amount of units you consumed: ");
    scanf(" %d", &Unit);
    if (Unit <= 199)
    {    
        charge = 16.2;
        bill = Unit * charge;
    }    
    else if (Unit >= 200 && Unit< 300)
    {
        charge = 20.1;
        bill = Unit * charge;
    }
    else if (Unit >= 300 && Unit< 500)
    {
        charge = 27.1;
        bill = Unit * charge;
    }
    else if (Unit >= 500)
    {
        charge = 35.9;
        bill = Unit * charge;
    }
    if (bill > 18000)
        bill = bill * 1.15;
        
    printf("Customer name is %c", Name);
    printf("Customer ID is %c", ID);
    printf("Units consumed are %d", Unit);
    printf("Amount charges at @Rs.%f per unit: %f", charge, bill);
}