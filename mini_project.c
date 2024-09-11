#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 20
#define MAX_TITLE_LENGTH 100
#define MAX_DESC_LENGTH 200
#define DATE_LENGTH 11

char titles[MAX_TASKS][MAX_TITLE_LENGTH];
char description[MAX_TASKS][MAX_DESC_LENGTH];
char dates[MAX_TASKS][DATE_LENGTH];

int task = -1;
int Next_task = 0;
int num_tasks = 0;

int get_new_task();
void add_task();
void delete_task();
void search();

int main(){
    int choice;
    do {
        printf("\nTask Management System\n");
        printf("Press 1 to add a new task.\n");
        printf("Press 2 to delete a task.\n");
        printf("Press 3 to search for a task.\n");
        printf("Press 0 to quit.\n");
        printf("Enter your choice: ");
        scanf("%i", &choice);
        getchar();

        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                add_task();
                break;
            case 2:
                delete_task();
                break;
            case 3:
                search();
                break;
            default:
                printf("Invalid choice! Please press a valid number.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

int get_new_task(){
    if (num_tasks >= MAX_TASKS)
    {
        return -1;
    }
    return Next_task++;
}

void add_task(){
    if (num_tasks >= MAX_TASKS)
    {
        printf("Task list is full.\n");
        return;
    }

    int next_task_index = get_new_task();
    if (next_task_index == -1)
    {
        printf("No tasks available.\n");
        return;
    }
    
    printf("Enter the title of the task : ");getchar();
    fgets(titles[next_task_index], MAX_TITLE_LENGTH, stdin);
    titles[next_task_index][strcspn(titles[next_task_index], "\n")] = '\0';

    printf("Enter the Description of the task : ");
    fgets(description[next_task_index], MAX_DESC_LENGTH, stdin);
    description[next_task_index][strcspn(description[next_task_index], "\n")] = '\0';

    printf("Enter the date of the task (YYYY-MM-DD) : ");
    fgets(dates[next_task_index], DATE_LENGTH, stdin);
    dates[next_task_index][strcspn(dates[next_task_index], "\n")] = '\0';

    num_tasks++;
}
void delete_task(){
    if (num_tasks == 0)
    {
        printf("There's no tasks to delete.\n");
        return;
    }

    char task_to_delete[MAX_TITLE_LENGTH];
    printf("Enter the task's name to delete it : ");
    fgets(task_to_delete, MAX_TITLE_LENGTH, stdin);
    task_to_delete[strcspn(task_to_delete, "\n")] = '\0';

    int found = -1;
    for (int i = 0; i < num_tasks; i++)
    {
        if (strcmp(titles[i], task_to_delete) == 1)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Task not found :(\n");
        return;
    }
    
    for (int i = found; i < num_tasks - 1; i++)
    {
        strcpy(titles[i],titles[i + 1]);
        strcpy(description[i],description[i + 1]);
        strcpy(dates[i],dates[i + 1]);
    }

    titles[num_tasks - 1][0] = '\0';
    description[num_tasks - 1][0] = '\0';
    dates[num_tasks - 1][0] = '\0';
    
    num_tasks--;
    printf("Task '%s' deleted successfully.\n",task_to_delete);
}
void search(){
    if (num_tasks == 0)
    {
        printf("There's no tasks to search for.\n");
        return;
    }

    char task_to_found[MAX_TITLE_LENGTH];
    fgets(task_to_found, MAX_TITLE_LENGTH, stdin);
    task_to_found[strcspn(task_to_found, "\n")] = '\0';

    int found = -1;
    for (int i = 0; i < num_tasks; i++)
    {
        if (strcmp(task_to_found,titles[i]) == 1)
        {
            found = i;
            printf("The task's name : %s.\n", titles[i]);
            printf("The task's description : %s.\n", description[i]);
            printf("The task's date : %s.\n", dates[i]);
            break;
        }
    }
    
    if (found == -1)
    {
        printf("Task not found.\n");
        return;
    }
}