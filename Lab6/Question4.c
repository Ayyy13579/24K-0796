#include <stdio.h>

int main() {
    int number = 65536,i;
    for (i=1;number > 0;i++) {
        number = number / i;
        printf("%d\n", number);
    }
}