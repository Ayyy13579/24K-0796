#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index >= size) return -1;
    if (arr[index] == target) return index;
    return linearSearch(arr, size, target, index + 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int result = linearSearch(arr, size, target, 0);

    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);

    return 0;
}
