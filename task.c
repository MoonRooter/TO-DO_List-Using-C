#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

#define MAX_LEN 100

typedef struct TaskNode {
    char task[MAX_LEN];
    int completed;
    struct TaskNode *next;
} TaskNode;

TaskNode *head = NULL;

void addTask() {
    TaskNode *newNode = (TaskNode*)malloc(sizeof(TaskNode));

    printf("Enter task: ");
    getchar(); // clear buffer
    fgets(newNode->task, MAX_LEN, stdin);

    newNode->task[strcspn(newNode->task, "\n")] = 0;
    newNode->completed = 0;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    } else {
        TaskNode *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }

    printf("Task added!\n");
}

void viewTasks() {
    TaskNode *temp = head;
    int i = 1;

    if(!temp){
        printf("No tasks found!\n");
        return;
    }

    while(temp){
        printf("%d. [%s] %s\n", i,
            temp->completed ? "compeletd" : "pending" ,
            temp->task);
        temp = temp->next;
        i++;
    }
}

void completeTask() {
    int n, i = 1;
    printf("Enter task number: ");
    scanf("%d", &n);

    TaskNode *temp = head;

    while(temp && i < n){
        temp = temp->next;
        i++;
    }

    if(temp){
        temp->completed = 1;
        printf("Task marked complete!\n");
    } else {
        printf("Invalid task number!\n");
    }
}