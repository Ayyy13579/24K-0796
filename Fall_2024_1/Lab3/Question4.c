#include <stdio.h>

int main()
{
    float fuelavg, fuelconsumed, forwardtrip, returntrip, totalprice;
    printf("Enter your car's fuel average: ");
    scanf("%f", &fuelavg);
    if (fuelavg < 0)
        printf("Invalid fuel average");
    else    
        fuelconsumed = 1207 / fuelavg;
        forwardtrip = 118 * fuelconsumed;
        returntrip = 123 * fuelconsumed;
        printf("Fuel consumed is %f\n", fuelconsumed);
        totalprice = forwardtrip + returntrip;
        printf("Fuel price is %f", totalprice);
    return 0;
}