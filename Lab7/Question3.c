#include <stdio.h>

int main()
{
    int array[10] = {}, i, max=0, min=1000;
    
    for (i=0;i<10;i++) {
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }
    for (i=0;i<10;i++) {
        if (array[i]> max) {
            max = array[i];
        }
        else if (array[i] < min) {
            min = array[i];
        }
    }
    printf("Maximum number is %d \n", max);
    printf("Minimum number is %d \n", min);
}