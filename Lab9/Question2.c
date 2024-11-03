#include <stdio.h>

void main() {
    evenorodd(5);
}

int evenorodd(num) {
    if (num % 2 == 0) {
        printf("Number is even.");
    } else {
        printf("Number is odd.");
    }
}