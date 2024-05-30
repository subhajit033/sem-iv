

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
typedef struct Job
{

    char id;    // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
} Job;

int compare(const void *a, const void *b)
{
    Job *temp1 = (Job *)a;
    Job *temp2 = (Job *)b;
    return (temp2->profit - temp1->profit);
}

int findMaxDeadLine(Job arr[], int n)
{
    int ans = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].dead > ans)
        {
            ans = arr[i].dead;
        }
    }
    return ans;
}

void display(Job arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d - ", arr[i].profit);
    }
}

void resolve(Job arr[], int n)
{
    int maxDeadline = findMaxDeadLine(arr, n);
    
    qsort(arr, n, sizeof(Job), compare);
    
    int dead_line[maxDeadline];
    int luv = 0;
    for (int i = 0; i < maxDeadline; i++)
    {
        dead_line[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (dead_line[arr[i].dead - 1] == -1)
        {
            printf("%c \n", arr[i].id);
            dead_line[arr[i].dead - 1] = 1;

            luv += arr[i].profit;
        }
        else
        {
            for (int j = 0; j <= arr[i].dead - 1; j++)
            {
                if (dead_line[j] == -1)
                {
                    printf("%c \n", arr[i].id);
                    dead_line[j] =1;
                    luv += arr[i].profit;
                    break;
                }
            }
        }
    }
    printf("max profit %d \n", luv);
}

int main()
{
    Job arr[] = {
        {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    resolve(arr, 5);
}