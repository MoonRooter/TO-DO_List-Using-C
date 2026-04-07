#include <stdio.h>
#include <string.h>
#include "user.h"

#define MAX_USERS 100

char usernames[MAX_USERS][50];
char passwords[MAX_USERS][50];
int userCount = 0;

char currentUser[50];

void mainMenu() {
    int option;

    printf("\n1. Login");
    printf("\n2. Register");
    printf("\nChoice: ");
    scanf("%d", &option);

    if(option == 1){
        if(!loginUser()){
            printf("Login failed\n");
        }
    }
    else if(option == 2){
        registerUser();
        if(!loginUser()){
            printf("Login failed\n");
        }
    }
}

void registerUser() {
    printf("\nRegister User\n");

    printf("Username: ");
    scanf("%s", usernames[userCount]);

    printf("Password: ");
    scanf("%s", passwords[userCount]);

    userCount++;

    printf("Registered successfully!\n");
}

int loginUser() {
    char username[50], password[50];

    printf("\nLogin Page\n");

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    for(int i = 0; i < userCount; i++){
        if(strcmp(username, usernames[i]) == 0 &&
           strcmp(password, passwords[i]) == 0){

            strcpy(currentUser, username);
            return 1;
        }
    }

    return 0;
}