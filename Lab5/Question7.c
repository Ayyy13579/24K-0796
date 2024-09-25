#include <stdio.h>

int main() {
    int a,b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("A is: %d\n",a);
    printf("B is: %d\n",b);
}