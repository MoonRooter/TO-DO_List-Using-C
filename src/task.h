#ifndef TASK_H
#define TASK_H

#define MAX_LEN 100

typedef struct TaskNode {
    char task[MAX_LEN];
    int completed;
    struct TaskNode *next;
} TaskNode;

extern TaskNode *head;
extern char fileName[100];

void loadTasks();
void saveTasks();
void addTask();
void viewTasks();
void markCompleted();
void deleteTask();
void deleteAllTask();

#endif