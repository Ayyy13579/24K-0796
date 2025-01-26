#include <stdio.h>

int main()
{
    int value, rate, timeperiod;
    float interest;
    printf ("Enter a value between 100 and 1,000,000: ");
    scanf ("%d",&value);
    printf ("Enter a rate of interest between 5 and 10: ");
    scanf ("%d",&rate);
    printf ("Enter a time period between 1 and 10 years: ");
    scanf ("%d",&timeperiod);
    interest = (timeperiod*rate*value)/100;
    printf ("The interest is: %f\n",interest);


}