#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[20];
    float marks;
};

int main() {
    int number;
    float average;
    printf("Enter the number of students in the class: ");
    scanf("%d", &number);
    struct Student* myclass = (struct Student*)malloc(number * sizeof(struct Student));
    if (myclass == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    for (int i = 0;i < number; i++) {
        printf("Enter Student %d's name: ", i+1);
        scanf("%s", myclass[i].name);
        printf("Enter Student %d's marks: ", i+1);
        scanf("%f", &myclass[i].marks);
    }
    for (int i=0; i < number; i++) {
        average += myclass[i].marks;
    }
    average = average / number;
    printf("The average marks for the class are %.2f", average);
}