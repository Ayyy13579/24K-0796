#include <stdio.h>
#include <math.h>

void main() {
    int lower,upper,i, j;
    printf("Enter the lower range: ");
    scanf("%d",lower);
    printf("Enter the upper range: ");
    scanf("%d",upper);
    printf("The list of prime numbers in your range are:\n");
    for (i=lower;i<=upper;i++) {
        if (i % 2 != 0 && i % 3 != 0 ) {
        for (j=5;j<=sqrt(i);j += 6) {
                if (i % j != 0 && i % (j+2) != 0) {
                    printf("%d ", i);
                }
            }
        }
    }
}