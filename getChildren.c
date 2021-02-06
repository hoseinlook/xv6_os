#include "types.h"
#include "user.h"
#include "types.h"


int main()
{
    int a = fork();
    int b = fork();
    
    if (a > 0)
        sleep(20);
    if (b > 0)
        sleep(10);
    

    printf(1, "PID: %d, getChildren: %d\n", getpid(), getChildren());
    
    wait();
    wait();
    exit();
}