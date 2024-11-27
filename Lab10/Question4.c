#include <stdio.h>
#include <string.h>


typedef struct {
    char make[50];
    char model[50];
    int year;
    double price;
    double mileage;
} Car;

Car cars[20];
int carCount = 0;

// Function to add a new car
void addCar() {
    if (carCount >= 20) {
        printf("Dealership is full!\n");
        return;
    }

    Car newCar;
    printf("Enter car details:\n");
    printf("Make: ");
    scanf("%s", newCar.make);
    printf("Model: ");
    scanf("%s", newCar.model);
    printf("Year: ");
    scanf("%d", &newCar.year);
    printf("Price: ");
    scanf("%lf", &newCar.price);
    printf("Mileage: ");
    scanf("%lf", &newCar.mileage);

    cars[carCount++] = newCar;
    printf("Car added successfully!\n");
}

void displayCars() {
    if (carCount == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("\nList of available cars:\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d:\n", i + 1);
        printf("  Make: %s\n", cars[i].make);
        printf("  Model: %s\n", cars[i].model);
        printf("  Year: %d\n", cars[i].year);
        printf("  Price: $%.2f\n", cars[i].price);
        printf("  Mileage: %.2f km\n", cars[i].mileage);
    }
}

void searchCars() {
    char searchQuery[50];
    printf("Enter make or model to search: ");
    scanf("%s", searchQuery);

    printf("\nSearch results for \"%s\":\n", searchQuery);
    int found = 0;
    for (int i = 0; i < carCount; i++) {
        if (strcasecmp(cars[i].make, searchQuery) == 0 || 
            strcasecmp(cars[i].model, searchQuery) == 0) {
            printf("Car %d:\n", i + 1);
            printf("  Make: %s\n", cars[i].make);
            printf("  Model: %s\n", cars[i].model);
            printf("  Year: %d\n", cars[i].year);
            printf("  Price: $%.2f\n", cars[i].price);
            printf("  Mileage: %.2f km\n", cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching \"%s\".\n", searchQuery);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add a new car\n");
        printf("2. Display all cars\n");
        printf("3. Search for cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                displayCars();
                break;
            case 3:
                searchCars();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
