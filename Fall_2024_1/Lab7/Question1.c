#include <stdio.h>

int main()
{
    int array[10] = {},i,sum = 0;

    for (i=0;i<10;i++) {
        printf("Enter element: ");
        scanf("%d", &array[i]);
        sum += array[i];
    }
    printf("%d", sum);
}