#include <stdio.h>

int main() {
    int a=1,b=2,i,factor;
    printf("%d\n", a);
    printf("%d\n", b);
    for (i=0;i<7;i++) {
        factor = a * b;
        printf("%d\n", factor);
        a = b;
        b = factor;
    }
}