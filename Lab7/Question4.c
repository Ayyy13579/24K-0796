#include <stdio.h>

void main() {
    int length, i;
    printf("Array size: ");
    scanf("%d", &length);
    int array[length], count[length];
    
    for (i=0; i<length; i++) {
        count[i] = 0;
    }
    for (i=0; i<length; i++ ) {
        printf("Element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    for (i=0;i<length;i++) {
        printf("%d ", array[i]);
        count[array[i]] +=1;
    }
    for (i=0;i<length;i++) {
        if (count[i] > 1) {
        printf("\n%d was repeated %d times", i,count[i]);
        }
    }
}