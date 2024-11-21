#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void encryptword(char word[20]);
void finaldecrypt(char word[20]);
void encryptword(char word[20]) {
    char encryptedword[20] = {};
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        encryptedword[i] = "_";
    }
    
    if (length < 5) {
        int hint = rand() % length;
        encryptedword[hint] = word[hint];
}
void finaldecrypt(char word[20]){
    printf("You lost.\n");
    printf("the word was %s", word);
}

char randomline(char filename[]) {
    FILE *file;
    int count=0;
    char words[100][20];
    file=fopen(filename,'r');
    while (fgets(words[count], sizeof(words[count]),file))
    {
        words[count][strcspn(words[count],"\n")]='\0';
        count++;
       
    }    
} 

void main() {
    int choice;
    while (1) {
    printf("Welcome to Hangman!\n");
    printf("Please choose a category to generate your word.\n");
    printf("1. Transport\n2. Fruits and Vegetables\n3. Countries\n4. Sport\n5. Animals\n6. Exit Program");
    printf("Choose your category: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char filename[] = "transport.txt";
        char word[20] = randomline(filename);
        encryptword(word);
        break;
    case 2:
        char filename[] = "fruits.txt";
        char word[20] = randomline(filename);
        encryptword(word);
        break;
    case 3:
        char filename[] = "country.txt";
        char word = randomline(filename);
        encryptword(word);
        break;
    case 4:
        char filename[] = "sports.txt";
        char word = randomline(filename);
        encryptword(word);
        break;
    case 5:
        char filename[] = "animal.txt";
        char word = randomline(filename);
        encryptword(word);
        break;
    case 6:
        printf("Exiting program...");
        break;
    default:
        printf("Please enter the correct category.");
        break;
    }
}
}




























