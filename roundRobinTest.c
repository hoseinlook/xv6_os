#include "types.h"
#include "user.h"

struct times {
    int creationTime;
    int terminationTime;
    int sleepingTime;
    int readyTime;
    int runningTime;
    int waitingTime;
};

int main(void)
{
    changePolicy(0);

    int TurnaroundTime = 0;
    int CBT = 0;
    int WaitingTime = 0;

    struct times timesArray[10];
    for (int j = 0; j < 10; j++)
    {
        if (fork() == 0)
        {
            for (int i = 0; i < 1000; i++)
                printf(1, "[%d]: [%d] \n", getpid(), i);
            exit();
        }
    }

    for (int k = 0; k < 10; k++)
        wait_and_get_info(timesArray);

    

    for (int k = 0; k < 10; k++)
    {
        WaitingTime += timesArray[k].waitingTime;
        CBT += timesArray[k].runningTime;
        TurnaroundTime += (timesArray[k].terminationTime - timesArray[k].creationTime);
        
        
        printf(1, "Child number : %d \n", (k + 1));
        printf(1, "Turnaround time : %d  \n", (timesArray[k].terminationTime - timesArray[k].creationTime));
        printf(1, "CBT : %d  \n", timesArray[k].runningTime);
        printf(1, "Waiting time : %d  \n", timesArray[k].readyTime);
        printf(1, "\n");
    }

    // calculating parameters
    int childNumber = 10;
    int avgTurnaroundTime = TurnaroundTime / childNumber;
    int avgCBT = CBT / childNumber;
    int avgWaitingTime = WaitingTime / childNumber;

    printf(1, "All Processes : \n");
    printf(1, "Average Turnaround time : %d  \n", avgTurnaroundTime);
    printf(1, "Average CBT : %d  \n", avgCBT);
    printf(1, "Average Waiting time : %d  \n", avgWaitingTime);

    exit();
}