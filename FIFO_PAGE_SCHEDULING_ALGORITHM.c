#include <stdio.h>
#include <string.h>
struct process
{
    char s[100];
    int at, bt, ct, wt, tat;
} ;
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name, arrival time and burst time of process %d: ", i + 1);
        scanf("%s%d%d", p[i].s, &p[i].at, &p[i].bt);
    }
    // sorting processes by arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)// if arrival time of process j is greater than arrival time of process j+1, then swap them
            {
                struct process temp = p[j]; // swap process j and process j+1
                p[j] = p[j + 1]; // swap process j and process j+1
                p[j + 1] = temp;
            }
        }
    }
    p[0].ct = p[0].at + p[0].bt; // completion time of first process

    for (int i = 1; i < n; i++) // calculating completion time of remaining processes
    {
        if (p[i].at > p[i - 1].ct) // CPU was idle!
            p[i].ct = p[i].at + p[i].bt; // completion time of process i
        else // CPU was not idle
            p[i].ct = p[i - 1].ct + p[i].bt; // completion time of process i
    } 
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\n");
    for (int i=0;i<n;i++){
        printf("%s\t%d\t%d\t\t%d\t\t%d\n",p[i].s,p[i].at,p[i].bt,p[i].ct,p[i].ct-p[i].at);
    }
    return 0;
}
