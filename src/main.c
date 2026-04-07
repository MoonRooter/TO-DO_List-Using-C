#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "task.h"
#include "task.c"
#include "user.c"

int main() {
    int choice;

    printf("====== TO-DO LIST MANAGER ======\n");
    mainMenu();  // take the data from mainmenu
    loadTasks(); // take the data from laodtask

    while (1) {
        printf("\n====== TO-DO LIST ======\n");
        printf("User: %s\n", currentUser); // print name of user
        printf("\n1. Add Task");
        printf("\n2. View Tasks");
        printf("\n3. Mark Completed");
        printf("\n4. Delete Task");
        printf("\n5. Delete All Tasks");
        printf("\n6. Exit");

        printf("\nEnter choice: ");

        if(scanf("%d", &choice) != 1){
            printf("Invalid input\n");
            while(getchar() != '\n');
            continue;
        }
        getchar();

        switch(choice){
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: deleteTask(); break;
            case 6: 
                saveTasks(); 
                printf("Saved & Exit\n"); 
                exit(0);
            case 5:
               deleteAllTask(); break;
            default: printf("Invalid choice\n");
        }
    }
}
