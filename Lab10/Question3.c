#include <stdio.h>

const templimit = 100;

int comparetemp(int temperature[]) {
    int count = 0;
    for (int i=0;i<10;i++) {
        if (temperature[i] > templimit) {
        count++;
        }
    }
    return count;
}

int main() {
    int temperature[10] = {23,134,34,67,789,56,34,56,343,1};
    int value = comparetemp(temperature);
    printf("%d", value);
}