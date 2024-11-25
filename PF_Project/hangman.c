#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


void encryptword(char word[20], char encryptedword[20]) {
    int length = strlen(word), i=0;
    int randomindex[length];
    int countrandomindex=0;
    for ( int i = 0; i < length; i++) {
        randomindex[i]=countrandomindex;
        countrandomindex++;
    }
    
    for (int i = 0; i < length; i++) {
        encryptedword[i] = '_';
    }
    encryptedword[length] = '\0';
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
}
}

void savescore(char filename[],int *tries, char word[20]){
    FILE *scores;
    char udelete;
    scores=fopen(filename,"a");
    int triesused = 7 - (*tries);
    int score= 70 - (triesused*10);
    printf("You got a total score of %d out of 70.\n",score);
    printf("You used %d tries.\n", triesused);
    fprintf(scores,"For the word %s:\n",word);
    fprintf(scores,"You got a total score of %d out of 70.\n",score);
    fclose(scores);
}

void finaldecrypt(char word[20], char result){
    if (result == 'N') {
        printf("\nYou lost.\n");
        printf("The word was %s", word);
    } else {
        printf("\nYou won.\n");
    }
}



void randomline(char filename[],char word[20]) {
    FILE *file;
    int count=0;
    char words[24][20];
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file.\n");
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

char takeInput() {
    char alphabet = ' ';
    while ((alphabet < 'a' || alphabet > 'z') && (alphabet < 'A' || alphabet > 'Z')) {
        printf("\nEnter a letter to guess: ");
        alphabet = getchar();
        while ((getchar()) != '\n');
    }
    return alphabet;
}

char compare(char userchoice,int *tries, char word[20], char encryptedword[20]) {
    int charindex = 0;
    char found = 'F', gameOver = 'F', guessedchar[7];
    for (int i=0;i<strlen(word); i++) {
        if (userchoice == word[i] || (userchoice + 32) == word[i]) {
            found = 'T';
            encryptedword[i] = word[i];
        }
    }
    if (found == 'T') {
        printf("Letter %c found in the word. You still have %d tries left.\n", userchoice, *tries);
        fputs(encryptedword,stdout);
        if (strcmp(word,encryptedword) == 0) {
            finaldecrypt(word, 'Y');
            gameOver = 'T';
        }
    } else {
        (*tries)--;
        printf("Word not found. You now have %d tries left.\n", *tries);
        printf("Hangman is now as follows:\n");
        displayHangman(*tries);
        fputs(encryptedword,stdout);
        if ((*tries) == 0) {
            finaldecrypt(word, 'N');
            gameOver = 'T';
        }
    }
    return gameOver;
}

void displayHangman(int tries) {
    switch (tries) {
    case 6:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|      \n");
        printf("|      \n");
        printf("|      \n");
        printf("=========\n");
        break;
    case 5:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|   o  \n");
        printf("|      \n");
        printf("|      \n");
        printf("=========\n");
        break;
    case 4:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|   o   \n");
        printf("|   |  \n");
        printf("|      \n");
        printf("=========\n");
        break;
    case 3:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|   o  \n");
        printf("|  /|  \n");
        printf("|      \n");
        printf("=========\n");
        break;
    case 2:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|   o  \n");
        printf("|  /|\\ \n");
        printf("|      \n");
        printf("=========\n");
        break;
    case 1:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|   o  \n");
        printf("|  /|\\  \n");
        printf("|  /   \n");
        printf("=========\n");
        break;
    case 0:
        printf("+---+  \n");
        printf("|   |  \n");
        printf("|   o  \n");
        printf("|  /|\\ \n");
        printf("|  / \\ \n");
        printf("=========\n");
        break;
    default:
        printf("Hangman cannot be displayed.");
        break;
    }
}

void main() {
    char word[20], encryptedword[20], filename[20], alpha, correct = 'T';
    printf("Welcome to Hangman!\n\n");
    
    while (1) {
    char gameOver = 'F';
    int tries = 7, choice1, choice2;
    printf("Choose an option to perform:\n");
    printf("1. Play Hangman.\n");
    printf("2. View Scores.\n");
    printf("3. Exit Program.\n\n");
    printf("Choose your choice: ");
    scanf("%d", &choice1);
    while ((getchar()) != '\n');

    if (choice1 == 1) {

        printf("Please choose a category to generate your word.\n");
        printf("1. Transport\n2. Fruits and Vegetables\n3. Countries\n4. Sport\n5. Animals\n6. Exit Program\n");
        printf("Choose your category: ");
        scanf("%d", &choice2);
        while ((getchar()) != '\n'); 
        
        switch (choice2) {
        case 1:
            printf("Transport category chosen. Generating word...\n");
            strcpy(filename, "transport.txt");
            randomline(filename,word);
            encryptword(word, encryptedword);
            printf("Your word is: %s\n", encryptedword);
            while (gameOver == 'F') {
            alpha = takeInput();
            gameOver = compare(alpha,&tries,word,encryptedword);
            }
            savescore("scores.txt", &tries, word);
            break;
        case 2:
            printf("Fruits category chosen. Generating word...\n");
            strcpy(filename, "fruits.txt");
            randomline(filename,word);
            encryptword(word, encryptedword);
            printf("Your word is: %s\n", encryptedword);
            while (gameOver == 'F') {
                alpha = takeInput();
                gameOver = compare(alpha,&tries,word,encryptedword);
            }
            savescore("scores.txt", &tries, word);
            break;
        case 3:
            printf("Country category chosen. Generating word...\n");
            strcpy(filename, "country.txt");
            randomline(filename,word);
            encryptword(word, encryptedword);
            printf("Your word is: %s\n", encryptedword);
            while (gameOver == 'F') {
                alpha = takeInput();
                gameOver = compare(alpha,&tries,word,encryptedword);
            }
            savescore("scores.txt", &tries, word);
            break;
        case 4:
            printf("Sports category chosen. Generating word...\n");
            strcpy(filename, "sports.txt");
            randomline(filename,word);
            encryptword(word, encryptedword);
            printf("Your word is: %s\n", encryptedword);
            while (gameOver == 'F') {
                alpha = takeInput();
                gameOver = compare(alpha,&tries,word,encryptedword);
            }
            savescore("scores.txt", &tries, word);
            break;
        case 5:
            printf("Animal category chosen. Generating word...\n");
            strcpy(filename, "animal.txt");
            randomline(filename,word);
            encryptword(word, encryptedword);
            printf("Your word is: %s\n", encryptedword);
            while (gameOver == 'F') {
                alpha = takeInput();
                gameOver = compare(alpha,&tries,word,encryptedword);
            }
            savescore("scores.txt", &tries, word);
            break;
        case 6:
            printf("Exiting program...");
            correct = 'F';
            break;
        default:
            printf("Please enter a correct option from 1-6.\n");
            break;
        }
    } else if (choice1 == 2) {
        char storescores[100];
        FILE *scores;
        scores=fopen("scores.txt","r");
        if (scores == NULL) {
                printf("No records found.\n");
            } else {
                while (fgets(storescores, sizeof(storescores), scores)) {
                    printf("%s", storescores);
                }
                fclose(scores);
            }
        char udelete[10]; 
        while (1) {
            printf("Do you want to delete your previous records (Y/N): ");
            fgets(udelete, sizeof(udelete), stdin);  
            
            if (udelete[0] == '\n') {
                continue;  
            }

            udelete[0] = toupper(udelete[0]);  

            if (udelete[0] == 'Y' || udelete[0] == 'N') {
                break;  
            } else {
                printf("Invalid input! Please enter 'Y' or 'N'.\n");
            }
            }
        
            if (udelete[0]=='Y')
            {
                if (remove("scores.txt")==0)
                {
                printf("Records deleted successfully.\n");
                }
                else
                {
                printf("Couldnt delete records.\n");
                }
            }
        } else if (choice1 == 3) {
            printf("Exiting Program...\n");
            break;
        } else {
        printf("Incorrect choice! Please enter an option from 1 - 3.\n");
    }
}
}