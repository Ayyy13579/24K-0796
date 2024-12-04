#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[20];
    char author[20];
    int publicationYear;
};

struct Library {
    struct Book* myBooks;
};

int main() {
    struct Library myLib;
    myLib.myBooks = (struct Book*)malloc(5 * sizeof(struct Book));
    if (myLib.myBooks == NULL) {
        printf("Memory allocation failed.");
    }
    for (int i = 0; i < 5; i++) {
        printf("Enter title of Book %d: ", i+1);
        scanf("%s", myLib.myBooks[i].title);
        printf("Enter author of Book %d: ", i+1);
        scanf("%s", myLib.myBooks[i].author);
        printf("Enter publication year of Book %d: ", i+1);
        scanf("%d", &myLib.myBooks[i].publicationYear);
    }
    for (int i = 0; i < 5; i++) {
        if (myLib.myBooks[i].publicationYear > 2000) {
            printf("%s\n", myLib.myBooks[i].title);
        }
    }
}