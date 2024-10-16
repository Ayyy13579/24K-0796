#include <stdio.h>

void main() {
    int length, i;
    printf("Enter number of elements in the array: ");
    scanf("%d", &length);
    int list[length];

    for (i=0; i<length; i++ ) {
        printf("Enter element: ");
        scanf("%d", &list[i]);
    }
    printf("Array in reverse order: \n");
    for (i=length-1;i>=0;i--) {
        printf("%d ", list[i]);
    }
}