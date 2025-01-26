#include <stdio.h>

int main() {
    float attendance, assignment, exam, result;
    printf("Enter attendance out of 100: ");
    scanf("%f", &attendance);
    printf("Enter assignment marks out of 20: ");
    scanf(" %f", &assignment);
    printf("Enter your final exam result out of 80: ");
    scanf(" %f", &exam);
    if (attendance > 80) {
        result = exam + assignment;
        if (result > 90) {
            printf("Grade is A*");
        }
        else if (result > 80) {
            printf("Grade is A");
        }
        else if (result > 70) {
            printf("Grade is B");
        }
        else if (result > 60) {
            printf("Grade is C");
        }
        else if (result > 50) {
            printf("Grade is D");
        }
        else {
            printf("You have failed");
        }
    }
    else {
        printf("Attendance not enough, failed");
    }
}