#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

typedef struct {
    char name[50];
    char destination[50];
    int duration;
    double cost;
    int seatsAvailable;
} TravelPackage;

TravelPackage packages[MAX_PACKAGES];
int packageCount = 0;

void addPackage(const char *name, const char *destination, int duration, double cost, int seatsAvailable) {
    if (packageCount >= MAX_PACKAGES) {
        printf("Cannot add more packages. Maximum limit reached.\n");
        return;
    }

    TravelPackage newPackage;
    strcpy(newPackage.name, name);
    strcpy(newPackage.destination, destination);
    newPackage.duration = duration;
    newPackage.cost = cost;
    newPackage.seatsAvailable = seatsAvailable;

    packages[packageCount++] = newPackage;
}

void displayPackages() {
    if (packageCount == 0) {
        printf("No travel packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < packageCount; i++) {
        printf("Package %d:\n", i + 1);
        printf("  Name: %s\n", packages[i].name);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d days\n", packages[i].duration);
        printf("  Cost: $%.2f per person\n", packages[i].cost);
        printf("  Seats Available: %d\n", packages[i].seatsAvailable);
        printf("\n");
    }
}

void bookPackage() {
    int choice, seats;
    displayPackages();

    if (packageCount == 0) {
        return;
    }

    printf("Enter the package number you want to book: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > packageCount) {
        printf("Invalid package number!\n");
        return;
    }

    TravelPackage *selectedPackage = &packages[choice - 1];
    printf("Enter the number of seats to book: ");
    scanf("%d", &seats);

    if (seats > selectedPackage->seatsAvailable) {
        printf("Not enough seats available. Only %d seats left.\n", selectedPackage->seatsAvailable);
    } else {
        selectedPackage->seatsAvailable -= seats;
        printf("Booking successful! %d seats booked for package \"%s\" to %s.\n",
               seats, selectedPackage->name, selectedPackage->destination);
    }
}

int main() {
    addPackage("Beach Getaway", "Hawaii", 7, 1500.0, 10);
    addPackage("Cultural Tour", "Japan", 5, 1200.0, 8);
    addPackage("Safari Adventure", "Kenya", 10, 2000.0, 5);

    int choice;
    do {
        printf("\nTravel Package Booking System\n");
        printf("1. Display available packages\n");
        printf("2. Book a package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages();
                break;
            case 2:
                bookPackage();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
