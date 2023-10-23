#include <stdio.h>
#include <stdlib.h>

// Constants
#define MinQuantity 5

// Product details
float itemAPrice = 1.0;
int itemAQuantity = 10;
char itemNameA = 'A';

float itemBPrice = 2.0;
int itemBQuantity = 15;
char itemNameB = 'B';

float itemCPrice = 1.5;
int itemCQuantity = 7;
char itemNameC = 'C';

// Admin password
int adminPassword = 1234;

// Sales total
float totalSales = 0.0;

// Function prototypes
void displayMenu();
void purchaseItem();
void adminMode();
void replenishItems();
void changeItemPrices();
void displayTotalSale();
void displayItemAvailability();

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                purchaseItem();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("Main Menu\n");
    printf("1. Purchase Item\n");
    printf("2. Admin Mode\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void purchaseItem() {
    int itemChoice;
    float itemPrice;
    int* itemQuantity;
    char itemName;

    printf("Available Items:\n");
    printf("1. Item %c - $%.2f (Qty: %d)\n", itemNameA, itemAPrice, itemAQuantity);
    printf("2. Item %c - $%.2f (Qty: %d)\n", itemNameB, itemBPrice, itemBQuantity);
    printf("3. Item %c - $%.2f (Qty: %d)\n", itemNameC, itemCPrice, itemCQuantity);
    printf("Enter the item number to purchase (0 to cancel): ");
    scanf("%d", &itemChoice);

    switch (itemChoice) {
        case 1:
            itemPrice = itemAPrice;
            itemQuantity = &itemAQuantity;
            itemName = itemNameA;
            break;
        case 2:
            itemPrice = itemBPrice;
            itemQuantity = &itemBQuantity;
            itemName = itemNameB;
            break;
        case 3:
            itemPrice = itemCPrice;
            itemQuantity = &itemCQuantity;
            itemName = itemNameC;
            break;
        case 0:
            printf("Purchase canceled.\n");
            return;
        default:
            printf("Invalid item choice.\n");
            return;
    }

    printf("You selected Item %c - $%.2f\n", itemName, itemPrice);

    float insertedAmount = 0.0;
    float coin;

    while (insertedAmount < itemPrice) {
        printf("Insert a coin (1, 0.5, 0.25 Dh) or 0 to cancel: ");
        scanf("%f", &coin);

        if (coin == 1 || coin == 0.5 || coin == 0.25) {
            insertedAmount += coin;
        } else if (coin == 0) {
            printf("Purchase canceled.\n");
            return;
        } else {
            printf("Invalid coin. Try again.\n");
        }
    }

    *itemQuantity -= 1;
    totalSales += itemPrice;

    printf("You purchased Item %c for $%.2f. Change: $%.2f\n", itemName, itemPrice, insertedAmount - itemPrice);

    if (*itemQuantity <= MinQuantity) {
        printf("Alert: Low quantity for Item %c!\n", itemName);
    }
}

void adminMode() {
    int password;
    printf("Enter the admin password: ");
    scanf("%d", &password);

    if (password != adminPassword) {
        printf("Incorrect admin password. Exiting Admin Mode.\n");
        return;
    }

    int adminChoice;
    
    while (1) {
        printf("Admin Menu\n");
        printf("1. Replenish Items\n");
        printf("2. Change Item Prices\n");
        printf("3. Display Total Sale\n");
        printf("4. Display Item Availability\n");
        printf("0. Exit Admin Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &adminChoice);

        switch (adminChoice) {
            case 1:
                replenishItems();
                break;
            case 2:
                changeItemPrices();
                break;
            case 3:
                displayTotalSale();
                break;
            case 4:
                displayItemAvailability();
                break;
            case 0:
                printf("Exiting Admin Mode.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void replenishItems() {
    itemAQuantity = rand() % 20 + 1;
    itemBQuantity = rand() % 20 + 1;
    itemCQuantity = rand() % 20 + 1;
    printf("Item quantities replenished.\n");
}

void changeItemPrices() {
    printf("Enter the new price for Item %c: ", itemNameA);
    scanf("%f", &itemAPrice);
    printf("Enter the new price for Item %c: ", itemNameB);
    scanf("%f", &itemBPrice);
    printf("Enter the new price for Item %c: ", itemNameC);
    scanf("%f", &itemCPrice);
    printf("Item prices updated.\n");
}

void displayTotalSale() {
    printf("Total Sales: $%.2f\n", totalSales);
    int resetTotal;
    printf("Would you like to reset the total sale to zero? (1 for Yes, 0 for No): ");
    scanf("%d", &resetTotal);

    if (resetTotal == 1) {
        totalSales = 0.0;
        printf("Total sales reset to zero. Please collect the money.\n");
    }
}

void displayItemAvailability() {
    printf("Item %c - Quantity: %d\n", itemNameA, itemAQuantity);
    printf("Item %c - Quantity: %d\n", itemNameB, itemBQuantity);
    printf("Item %c - Quantity: %d\n", itemNameC, itemCQuantity);
}