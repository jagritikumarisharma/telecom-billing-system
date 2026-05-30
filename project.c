#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10  // Define a max length for names

int main() {
    char names[100][MAX_NAME_LENGTH];  // Limit to 100 records
    char phone_numbers[100][10];       // Store up to 100 phone numbers
    float payments[100];
    int record_count = 0;
    int choice, i;

    while (1) {
        printf("\nTelecom Billing System Menu\n");
        printf("1. Add New Record\n");
        printf("2. View List of Records\n");
        printf("3. Modify Record\n");
        printf("4. View Payments\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (record_count < 100) {  // Use a variable to control record limit
                    printf("Enter customer name (max 9 characters): ");
                    scanf("%s", names[record_count]);
                    printf("Enter phone number (max 9 digits): ");
                    scanf("%s", phone_numbers[record_count]);
                    printf("Enter payment amount: ");
                    scanf("%f", &payments[record_count]);
                    record_count++;
                    printf("Record added successfully!\n");
                } else {
                    printf("Record limit reached. Cannot add more records.\n");
                }
                break;

            case 2:
                printf("List of Records:\n");
                for (i = 0; i < record_count; i++) {
                    printf("Customer %d: Name: %s, Phone: %s, Payment: %.2f\n", 
                        i + 1, names[i], phone_numbers[i], payments[i]);
                }
                break;

            case 3:
                printf("Enter the record number to modify (1-%d): ", record_count);
                int modify_index;
                scanf("%d", &modify_index);
                modify_index--;

                if (modify_index >= 0 && modify_index < record_count) {
                    printf("Modify customer name: ");
                    scanf("%s", names[modify_index]);
                    printf("Modify phone number: ");
                    scanf("%s", phone_numbers[modify_index]);
                    printf("Modify payment amount: ");
                    scanf("%f", &payments[modify_index]);
                    printf("Record updated successfully!\n");
                } else {
                    printf("Invalid record number.\n");
                }
                break;

            case 4:
                printf("Payment Details:\n");
                for (i = 0; i < record_count; i++) {
                    printf("Customer %d: Name: %s, Payment: %.2f\n", i + 1, names[i], payments[i]);
                }
                break;

            case 5:
                printf("Enter the record number to delete (1-%d): ", record_count);
                int delete_index;
                scanf("%d", &delete_index);
                delete_index--;

                if (delete_index >= 0 && delete_index < record_count) {
                    // Shift all records down to delete the specified one
                    for (i = delete_index; i < record_count - 1; i++) {
                        strcpy(names[i], names[i + 1]);
                        strcpy(phone_numbers[i], phone_numbers[i + 1]);
                        payments[i] = payments[i + 1];
                    }
                    record_count--;
                    printf("Record deleted successfully!\n");
                } else {
                    printf("Invalid record number.\n");
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}