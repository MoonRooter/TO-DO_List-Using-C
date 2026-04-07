#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

TaskNode *head = NULL;
extern char fileName[100];

void loadTasks() {
    FILE *f = fopen(fileName, "r");  
    if(!f) return;

    while(1){
        TaskNode *newNode = malloc(sizeof(TaskNode));

        if(fscanf(f,"%[^\t]\t%d\n",newNode->task,&newNode->completed)!=2){  //It is reading one task from the file into your linked list node.
                                                                            // scan a set of characters= %[...]
                                                                            // NOT= ^
                                                                            //\t= tab
            free(newNode); break;
        }

        newNode->next = head;
        head = newNode;
    }
    fclose(f);
}

void addTask() {
    TaskNode *newNode = (TaskNode *)malloc(sizeof(TaskNode));

    printf("Enter task: ");
    fgets(newNode->task, MAX_LEN, stdin);
    
    int len = strlen(newNode->task);
  
    if(newNode->task[len - 1] == '\n') {  // Check Last Character
         newNode->task[len - 1] = '\0';  // Remove Newline
    } 
    
    TaskNode *temp = head;
    while(temp){
    if(strcmp(temp->task, newNode->task) ==0){ //it comapare the task present in file called temp with task enter by user called newNode
        printf("Task is already exists!\n");
        free(newNode);
        return;
    }
    temp = temp->next;
}
    newNode->completed = 0;
    newNode->next = head;
    head = newNode;

    saveTasks();
    printf("Task added!\n");
}

void viewTasks() {
    if(!head){
        printf("No tasks\n");
        return;
    }

    TaskNode *temp = head;
    int i = 1;

    printf("\n--- Task List ---\n");

    while(temp){
        printf("%d. %s - %s\n",i++,temp->task,temp->completed ? "Completed" : "Pending"); // first show the task id then task name or if it was completed or pending 
        temp = temp->next;
    }
}

void markCompleted() {
    int n,i=1;
    viewTasks();
    printf("Enter number: ");
    scanf("%d",&n);

    TaskNode *temp=head;
    while(temp && i<n){
        temp=temp->next; i++; 
    } 

    if(temp){
        temp->completed=1;
        saveTasks();
        printf("Task marked as completed!\n");
    } else printf("Invalid\n");
}

void deleteTask() {
    int n,i=1;
    viewTasks();
    printf("Enter number: ");
    scanf("%d",&n);

    TaskNode *temp=head,*prev=NULL;

    while(temp && i<n){
        prev=temp;
        temp=temp->next;
        i++;
    }

    if(!temp){
        printf("Invalid\n");
        return;
    }

    if(prev==NULL) 
    head=temp->next;
    else prev->next=temp->next;

    free(temp);
    saveTasks();
    printf("Task deleted!\n");
}

void saveTasks() {
    FILE *f = fopen(fileName,"w");
    TaskNode *temp=head;

    while(temp){
        fprintf(f,"%s\t%d\n",
        temp->task,temp->completed);
        temp=temp->next;
    }
    fclose(f);
}

void deleteAllTask(){
    viewTasks();
    TaskNode *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All Task is deleted\n");
}