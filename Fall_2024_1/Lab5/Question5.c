#include <stdio.h>

int main() {
    int a,b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    (a > b) ? printf("A is bigger") : printf("B is bigger");
}