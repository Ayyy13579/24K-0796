#include <stdio.h>
#include <string.h>

void main() {
    char dest[10];
    char src[10];
    int num;
    printf("Enter the destination string: ");
    fgets(dest,10,stdin);
    dest[strcspn(dest,"\n")] ='\0';
    printf("Enter the source string: ");
    fgets(src,10,stdin);
    src[strcspn(dest,"\n")] ='\0';
    printf("Enter number of characters to concatenate: ");
    scanf("%d", &num);
    strncat(dest,src,num);
    printf("%s", dest);
}