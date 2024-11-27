#include <stdio.h>

#define M_TO_KM 0.001

void convertAndCount(double meters) {
    static int callCount = 0;
    callCount++;
    printf("%.2f meters = %.2f kilometers | Function called %d times\n", meters, meters * M_TO_KM, callCount);
}

int main() {
    convertAndCount(500);
    convertAndCount(1500);
    convertAndCount(300);
    return 0;
}
