#include <stdio.h>
#include <string.h>

void main() {
    char array[4][10] = {"zaid","umer","bilal","adnan"}, word[10], found = 'F';
    printf("Enter word to be found: ");
    fgets(word,10,stdin);
    word[strcspn(word,"\n")] ='\0';
    for (int i=0;i<4;i++) {
        if (strcmp(array[i],word) == 0) {
            printf("Found");
            found = 'T';
        }
    }
    if (found == 'F') {
        printf("Not Found");
    }
}