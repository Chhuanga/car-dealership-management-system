#include <stdio.h>
#include <stdlib.h>

struct customer {
    char name[50];
    char address[100];
    char phone[10];
    char email[50];
    char password[50];
    char username[50];
    int id;
};

void addCustomer() {
    struct customer customer;
    printf("Enter name: ");
    scanf("%s", customer.name);
    printf("Enter address: ");
    scanf("%s", customer.address);
    printf("Enter phone: ");
    scanf("%s", customer.phone);
    printf("Enter email: ");
    scanf("%s", customer.email);
    printf("Enter password: ");
    scanf("%s", customer.password);
    printf("Enter username: ");
    scanf("%s", customer.username);
    printf("Enter id: ");
    scanf("%d", &customer.id);

    FILE *file = fopen("customers.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %s %s %s %s %s %d\n", customer.name, customer.address, customer.phone, customer.email, customer.password, customer.username, customer.id);
    fclose(file);

    printf("Customer added successfully.\n");
}

void displayCustomers(){
    FILE *file=fopen("customers.txt","r");
    if (file==NULL){
        printf("Error opening file.\n");
        return;
    }
    struct customer customer;
    while (fscanf(file, "%s %s %s %s %s %s %d", customer.name, customer.address, customer.phone, customer.email, customer.password, customer.username, &customer.id) == true){
        printf("--------------------\n");
        printf("Name: %s\n", customer.name);
        printf("Address: %s\n", customer.address);
        printf("Phone: %s\n", customer.phone);
        printf("Email: %s\n", customer.email);
        printf("Username: %s\n", customer.username);
        printf("ID: %d\n", customer.id);
    }
    fclose(file);
}