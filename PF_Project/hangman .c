#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char encryptword(char word[20], char encryptedword[20]);
// void finaldecrypt(char word[20]);

char encryptword(char word[20], char encryptedword[20]) {
    int length = strlen(word), i = 0;
    int randomindex[length];
    int countrandomindex=0;
    for (int i = 0; i < length; i++) {
        randomindex[i]=countrandomindex;
        countrandomindex++;
    }
    
    for (int i = 0; i < length; i++) {
        encryptedword[i] = "_";
    }
    if (length <= 5) {
        int hint = rand() % length;
        randomindex[hint]=-1;
        encryptedword[hint] = word[hint];
    } else if (length <= 8) {
        while (i < 2) {
            int hint = rand() % length;
            if (randomindex[hint] != -1) {
                randomindex[hint]=-1;
                encryptedword[hint] = word[hint];
                i++;
            }
        }
    } else {
        while (i < 3) {
            int hint = rand() % length;
            if (randomindex[hint] != -1) {
                randomindex[hint]=-1;
                encryptedword[hint] = word[hint];
                i++;
            }
    }
    return encryptedword;
}
}


void finaldecrypt(char word[20]){
    printf("You lost.\n");
    printf("Te word was %s", word);
}



char randomline(char filename[],char word[20]) {
    FILE *file;
    int count=0;
    char words[24][20];
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    while (fgets(words[count], sizeof(words[count]),file))
    {
        words[count][strcspn(words[count],"\n")]='\0';
        count++;
    }
    fclose(file);
    srand(time(NULL));
    strcpy(word,words[rand() % count]);
}
void displayEncrypted() {
}

char compare(char userchoice,int tries, char word[20], char encryptedword[20]) {
    int charindex = 0;
    char found = 'F';
    for (int i=0;i<strlen(word); i++) {
        if (userchoice == word[i] || (userchoice + 32) == word[i]) {
            found = 'T';
            int charindex = i;
            break;
        }
    }
    if (found == 'T') {
        encryptedword[charindex] = word[charindex];
        fputs(encryptedword,stdout);
        printf("Letter %c found in the word. You still have %d tries left.", userchoice, tries);
    } else {
        tries--;
        printf("Word not found. You now have %d tries left.", tries);
        if (tries == 0) {
            finaldecrypt(word);
        }
    }
    return found;

}


void main() {
    int choice, tries = 7;
    char word[20], encryptedword[20];
    printf("Welcome to Hangman!\n");
    printf("Please choose a category to generate your word.\n");
    printf("1. Transport\n2. Fruits and Vegetables\n3. Countries\n4. Sport\n5. Animals\n6. Exit Program\n");
    printf("Choose your category: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char filename[] = "transport.txt";
        randomline(filename,word);
        encryptword(word, encryptedword);
        printf("Enter an alphabet ");
        break;
    case 2:
        char filename[] = "fruits.txt";
        randomline(filename,word);
        encryptword(word);
        break;
    case 3:
        char filename[] = "country.txt";
       randomline(filename,word);
        encryptword(word);
        break;
    case 4:
        char filename[] = "sports.txt";
        randomline(filename,word);
        encryptword(word);
        break;
    case 5:
        char filename[] = "animal.txt";
        randomline(filename,word);
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
