#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Account;

void deposit(Account *acc);
void withdraw(Account *acc);
void checkBalance(Account acc);
void saveToFile(Account acc);
void loadFromFile(Account *acc);

int main() {
    Account myAccount = {"User", 1001, 0.0f};
    int choice;

    
    loadFromFile(&myAccount);

    while (1) {
        printf("\n--- BANKING SYSTEM ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Balance Enquiry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(&myAccount);
                break;
            case 2:
                withdraw(&myAccount);
                break;
            case 3:
                checkBalance(myAccount);
                break;
            case 4:
                saveToFile(myAccount);
                printf("Data saved. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void deposit(Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Successfully deposited $%.2f\n", amount);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw(Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Successfully withdrew $%.2f\n", amount);
    } else {
        printf("Insufficient balance or invalid amount!\n");
    }
}

void checkBalance(Account acc) {
    printf("\nAccount Holder: %s", acc.name);
    printf("\nAccount Number: %d", acc.account_number);
    printf("\nCurrent Balance: $%.2f\n", acc.balance);
}

void saveToFile(Account acc) {
    FILE *file = fopen("account_data.dat", "wb");
    if (file != NULL) {
        fwrite(&acc, sizeof(Account), 1, file);
        fclose(file);
    }
}

void loadFromFile(Account *acc) {
    FILE *file = fopen("account_data.dat", "rb");
    if (file != NULL) {
        fread(acc, sizeof(Account), 1, file);
        fclose(file);
    }
}