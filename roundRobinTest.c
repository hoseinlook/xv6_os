#include "types.h"
#include "stat.h"
#include "user.h"

// struct times {
//     int creationTime;
//     int terminationTime;
//     int sleepingTime;
//     int readyTime;
//     int runningTime;
//     int waitingTime;
// };



int main(int argc, char *argv[])
    {   int j;

        int fork_num=100;
        int loop_count=4;
        int AVG_TURN[loop_count];

        for (j=0;j<loop_count;j++){
            changeQuantum(j*10+1);
            // printf(1,"QUANTUM= %d\n",j);
            // printf(1,"*************************\n");
            // printf(1,"your pid =%d\n",getpid());
            int creation_time=1;
            int waiting_time=1;
            int running_time=1;
            int termination_time=1;
            int sleeping_time=1;
            int pid =0;
            for (int i =0 ; i<fork_num ; ++i){
                pid =fork();
                
                if (pid==0){
                    for (int k = 0; k < 100; k++)
                    {
                        printf(1,"pid=%d ,%d\n",getpid(),k);
                    }
                    exit();    
                }
                else{
                    continue;
                }

            }
            // int child_list[10];
            int run_list[fork_num];
            int wait_list[fork_num];
            int create_list[fork_num];
            int terminate_list[fork_num];
            int sleeping_list[fork_num];
        
            for (int i = 0; i <fork_num ; i++)
                {
                    wait_and_get_info(&running_time,&waiting_time,&creation_time,&termination_time,&sleeping_time);
                    // child_list[i]=child_ID;
                    run_list[i]=running_time;
                    wait_list[i]=waiting_time;
                    create_list[i]=creation_time;
                    terminate_list[i]=termination_time;
                    sleeping_list[i]=sleeping_time;
                    
                }
            

        

            int run=0;
            int wait=0;
            int turn=0;

            for (int i = 0; i < fork_num; i++)
                {
                    run+=run_list[i];
                    wait+=wait_list[i];
                    turn+=terminate_list[i]-create_list[i]-sleeping_list[i];
                }
            
            printf(1,"AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d \n",
                    run/fork_num,wait/fork_num,turn/fork_num);
            AVG_TURN[j]=turn/fork_num;
        }
        

        for (j=0;j<loop_count;j++)
            printf(1,"qu= %d    avg turn=%d\n",j*10+1,AVG_TURN[j]);
        exit();
    }

