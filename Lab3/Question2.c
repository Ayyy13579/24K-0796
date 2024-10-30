#include <stdio.h>

int main()
{
    int a,b,temp; 
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    temp = b;
    b = a;
    a = temp;
    printf("value a is %d",a);
    printf("\nvalue b is %d",b);

}