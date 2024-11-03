#include <stdio.h>
#include <string.h>

void main() {
        char string[5][20] = {"hello","racecar","eeeee","great","radar"}, lastchar, isPal = 'T';
        int length, mid, j = 0;
        for (int i=0;i<5;i++) {
            j =0;
            isPal = 'T';
            length = strlen(string[i]);
            mid = length / 2;
            while (isPal == 'T' && j < mid) {
                lastchar = string[i][length - 1 - j];
                if (string[i][j] != lastchar) {
                    isPal = 'F';
                    j +=1;
                } else {
                    j +=1;
                }
            }
            if (isPal == 'T') {
                printf("String %d is a palindrome.\n", i+1);
            } else {
                printf("String %d is not a palindrome.\n", i+1);
            }
        }
}