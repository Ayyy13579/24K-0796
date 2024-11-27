#include <stdio.h>

void recursive(int array[], int size) {
    if (size == 0) {
        return;
    }
    printf("%d ", array[0]);
    recursive(array + 1,size - 1);
}

int main() {
    int array[6] = {1,2,3,4,5,6};
    recursive(array,6);
}