#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, sum;
    printf("Enter the number of values to input: ");
    scanf("%d", &number);
    int* array = (int *)malloc(number * sizeof(int));
    for (int i = 0; i < number; i++) {
        printf("Enter value for element %d: ", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < number; i++) {
        sum += array[i];
    }
    printf("Sum of values is %d", sum);
}