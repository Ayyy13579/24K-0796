#include <stdio.h>
#include <string.h>

void main() {
    stringreverse();
}

void stringreverse() {
    char string[10] = {"racecar"}, newstring[10] = {};
    int length, j=0;
    printf("The original string is %s\n", string);
    length = strlen(string);
    for (int i = length -1;i>-1;i--) {
        newstring[j] = string[i];
        j +=1;
    }
    printf("The reversed string is %s\n", newstring);
}