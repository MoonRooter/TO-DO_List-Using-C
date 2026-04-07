#include <stdio.h>
#include "user.h"
#include "task.h"

int main() {
    mainMenu();

    int choice;

    while(1){
        printf("\n--- TO DO MENU ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: completeTask(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}