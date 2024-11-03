#include <stdio.h>

void main() {
    function();
}

int function() {
    int array[5] = {6,4,2,8,1}, max = 0, min = 1000;
    for (int i = 0; i < 5; i++) {
        if (array[i] > max) {
            max = array[i];
        } else if (array[i] < min) {
            min = array[i];
        }
    }
    printf("The maximum number is %d.\n", max);
    printf("The minimum number is %d.\n", min);
}