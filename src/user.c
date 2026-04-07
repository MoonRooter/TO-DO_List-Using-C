#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define USERS_FILE "users.txt"

char currentUser[50];
char fileName[100];

void mainMenu() {
    int option;
    printf("\n1. Login");
    printf("\n2. Register");
    printf("\nchoice: ");
    scanf("%d", &option);
    getchar();
    
    if(option == 1){
        if(!loginUser()){
            printf("Login failed\n");
            exit(0);
        }
    }
    else if(option == 2){
        registerUser();
        if(!loginUser()){
            printf("Login failed\n");
            exit(0);
        }
    }
}

void registerUser() {
    char username[50], password[50];
    FILE *f;
    printf("\nRegister the User\n");
    printf("Username: "); 
    scanf("%s", username);
    printf("Password: "); 
    scanf("%s", password);

    f = fopen(USERS_FILE, "a");
    fprintf(f, "%s %s\n", username, password);
    fclose(f);

    printf("Registered successfully!\n");
}

int loginUser() {
    char username[50], password[50], u[50], p[50];
    FILE *f;
    printf("\n Login Page\n");
    printf("Username: "); 
    scanf("%s", username);
    printf("Password: "); 
    scanf("%s", password);

    f = fopen(USERS_FILE, "r");
    if(!f) return 0;

    while(fscanf(f,"%s %s",u,p)==2){
        if(strcmp(username,u)==0 && strcmp(password,p)==0){
            strcpy(currentUser, username);
            sprintf(fileName,"%s.txt",username);
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}