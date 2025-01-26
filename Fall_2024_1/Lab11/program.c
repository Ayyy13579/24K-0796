#include <stdio.h>

struct player{
char name[20];
char team[20];
} play;

struct bowl{
char type[10]; // seemer, pacer, spinner// N/A
char arm[5]; //left or right
} ply;

struct bat{
char type[10]; // top order, middle order, lower order
char handed[8]; //lefty or righty
} ply2;

int addBowler(struct bowl bowler) {
    FILE *file;
    file = fopen("bowlers.txt","a");
    if (file == NULL) {
        return -1;
    }
    printf("Enter name of the player: ");
    scanf("%s", play.name);
    fprintf(file, "%s\n",play.name);
    printf("Enter team: ");
    scanf("%s", play.team);
    fprintf(file, "%s\n",play.team);
    printf("Enter the role: ");
    scanf("%s", ply.type);
    fprintf(file, "%s\n",ply.type);
    printf("Enter arm: ");
    scanf("%s", ply.arm);
    fprintf(file, "%s\n", ply.arm);
    fclose(file);
}

int addBatsman(struct bat batsman) {
    FILE *file;
    file = fopen("batsman.txt","a");
    if (file == NULL) {
        return -1;
    }
    printf("Enter name of the player: ");
    scanf("%s", play.name);
    fprintf(file, "%s\n",play.name);
    printf("Enter team: ");
    scanf("%s", play.team);
    fprintf(file, "%s\n", play.team);
    printf("Enter the role: ");
    scanf("%s", ply2.type);
    fprintf(file, "%s\n", ply2.type);
    printf("Enter arm: ");
    scanf("%s", ply2.handed);
    fprintf(file, "%s\n", ply2.handed);
    fclose(file);
}

int displayPlayers() {
    char batsman[10], bowler[10];
    FILE *file1, *file2;
    file1 = fopen("batsman.txt","r");
    printf("Batsman: \n");
    while (fgets(batsman, sizeof(batsman), file1) != NULL) {
        printf("%s", batsman);
    }
    fclose(file1);
    file2 = fopen("bowlers.txt","r");
    printf("Bowler: \n");
    while (fgets(bowler, sizeof(bowler), file2) != NULL) {
        printf("%s", bowler);
    }
    fclose(file2);
}

int deletePlayers() {
    if (remove("batsman.txt") == 0) {
        printf("Batters successfully deleted.");
    }
    if (remove("bowlers.txt") == 0) {
        printf("Bowlers successfully deleted.");
    }

}

int main() {
    struct bowl newBowler;
    addBowler(newBowler);
    displayPlayers();
    deletePlayers();
}