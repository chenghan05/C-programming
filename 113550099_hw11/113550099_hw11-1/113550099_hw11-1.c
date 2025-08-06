#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRIORITY 32

typedef struct Task {
    char name[20];
    struct Task *next; 
} Task;

typedef struct {
    Task *tasks[MAX_PRIORITY]; 
    unsigned int priority_bitmap;
} Scheduler;

Task* create_task(char name[20]) {
    // allocate memory for the new task
    Task *newTask = (Task*)malloc(sizeof(Task));
    if (newTask == NULL) {
        perror("Failed to allocate memory for new task");
        exit(EXIT_FAILURE);
    }
    // TODO: copy the name and init other data into the task
    strcpy(newTask->name, name);
    newTask->next = NULL;
    // TODO: remember to return it
    return newTask;
}

void insert_task(Scheduler *scheduler, int priority, Task *newTask) {
    if (priority < 0 || priority >= MAX_PRIORITY) {
        printf("Invalid task priority: %d\n", priority);
        free(newTask);
        return;
    }
    // TODO: insert the task into the scheduler
    if(scheduler->priority_bitmap & (1U<<priority)){
        Task* temp = scheduler->tasks[priority];
        scheduler->tasks[priority] = newTask;
        newTask->next = temp;
    }else{
        scheduler->tasks[priority] = newTask;
    }
    scheduler->priority_bitmap |= (1U<<priority);
}

void execute_highest_priority_task(Scheduler *scheduler) {
    if (scheduler->priority_bitmap == 0) {
        printf("No tasks to execute.\n");
        return;
    }
    /*
        TODO: find the highest priority task
        You may want to use __builtin_clz to find the highest priority task
        or write your own code to find the highest priority task by bit operations
    */
    for(int i=31; i>=0; i--){
        if(scheduler->priority_bitmap & (1U<<i)){
            printf("Executing task: %s with priority %d\n", scheduler->tasks[i]->name, i);
            if(scheduler->tasks[i]->next == NULL){
                scheduler->priority_bitmap &= ~(1U<<i);
            }
            Task* temp = scheduler->tasks[i];
            scheduler->tasks[i] = scheduler->tasks[i]->next;
            free(temp);
            break;
        }
    }

    // TODO: remove the task from the scheduler and free the memory
}

int main() {
    Scheduler scheduler = {0};

    char operations[10] = "";
    
    while(scanf("%s", operations) != EOF) {
        if (strcmp(operations, "insert") == 0) {
            int priority;
            char name[20] = "";
            scanf("%d %s", &priority, name);
            insert_task(&scheduler, priority, create_task(name));
        } else if (strcmp(operations, "execute") == 0) {
            execute_highest_priority_task(&scheduler);
        }
    }

    // if there are remaining tasks, execute them
    while (scheduler.priority_bitmap != 0) {
        execute_highest_priority_task(&scheduler);
    }

    return 0;
}