#include <stdio.h>
#include <stdlib.h>

void derivative(int *coeffs, int degree) {
    printf("Derivative: ");
    for (int i = 0; i < degree; i++) {
        printf("%dx^%d", coeffs[i] * (degree - i), degree - i - 1);
        if (i < degree - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

void integral(int *coeffs, int degree) {
    printf("Integral: ");
    for (int i = 0; i <= degree; i++) {
        printf("%d/(%d)x^%d", coeffs[i] / (degree - i + 1), degree - i + 1, degree - i + 1);
        if (i < degree) {
            printf(" + ");
        }
    }
    printf(" + C\n");
}

int main() {
    int degree, choice;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    int *coeffs = (int *)malloc((degree + 1) * sizeof(int));

    printf("Enter the coefficients of the polynomial (from highest degree to constant):\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%d", &coeffs[i]);
    }

    printf("Choose the operation:\n");
    printf("1. Derivative\n");
    printf("2. Integral\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        derivative(coeffs, degree);
    } else if (choice == 2) {
        integral(coeffs, degree);
    } else {
        printf("Invalid choice. Please enter 1 for Derivative or 2 for Integral.\n");
    }

    free(coeffs);

    return 0;
}
