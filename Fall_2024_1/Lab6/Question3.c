#include <stdio.h>

int main() {
    int i,a = 1,b = 2,sum;
    printf("%d\n",a);
    printf("%d\n",b);
    for (i=0;i<=3;i++) {
        sum = a + b;
        printf("%d\n",sum);
        a = b;
        b = sum;
    }
}