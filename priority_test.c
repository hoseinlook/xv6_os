#include "types.h"
#include "stat.h"
#include "user.h"




int main(int argc, char *argv[])
    {   
            changePolicy(1);

            int fork_num=30;
        

        
            changeQuantum(1);
            // printf(1,"QUANTUM= %d\n",j);
            // printf(1,"*************************\n");
            // printf(1,"your pid =%d\n",getpid());
            int creation_time=1;
            int waiting_time=1;
            int running_time=1;
            int termination_time=1;
            int sleeping_time=1;
            int pid =0;
            int first=-1;
            for (int i =0 ; i<fork_num ; ++i){
                pid =fork();
                
                if (pid==0){
                    changePriority(i%6+1);
                    for (int k = 0; k < 250; k++)
                    {
                        printf(1,"pid=%d ,priority=%d k=%d\n",getpid(),get_priority(),k);
                    }
                    exit();    
                }
                else{
                    if (first==-1){
                        first=pid;
                    }
                    continue;
                }

            }
            // int child_list[10];
            int run_list[fork_num];
            int wait_list[fork_num];
            int create_list[fork_num];
            int terminate_list[fork_num];
            int sleeping_list[fork_num];

             int run=0;
            int wait=0;
            int turn=0;

        
            int run1=0;
            int wait1=0;
            int turn1=0;

            int run2=0;
            int wait2=0;
            int turn2=0;

            int run3=0;
            int wait3=0;
            int turn3=0;

            int run4=0;
            int wait4=0;
            int turn4=0;

            int run5=0;
            int wait5=0;
            int turn5=0;

            int run6=0;
            int wait6=0;
            int turn6=0;
            
            for (int i = 0; i <fork_num ; i++)
                {
                    pid=wait_and_get_info(&running_time,&waiting_time,&creation_time,&termination_time,&sleeping_time);
                    // child_list[i]=child_ID;
                    if ((pid-first)%6==0){
                         run6+=running_time;
                         wait6+=waiting_time;
                         turn6+=termination_time-creation_time-sleeping_time;
                    }
                    if ((pid-first)%6==1){
                         run1+=running_time;
                         wait1+=waiting_time;
                         turn1+=termination_time-creation_time-sleeping_time;
                    }
                    if ((pid-first)%6==2){
                         run2+=running_time;
                         wait2+=waiting_time;
                         turn2+=termination_time-creation_time-sleeping_time;
                    }
                    if ((pid-first)%6==3){
                         run3+=running_time;
                         wait3+=waiting_time;
                         turn3+=termination_time-creation_time-sleeping_time;
                    }
                    if ((pid-first)%6==4){
                         run4+=running_time;
                         wait4+=waiting_time;
                         turn4+=termination_time-creation_time-sleeping_time;
                    }
                    if ((pid-first)%6==5){
                         run5+=running_time;
                         wait5+=waiting_time;
                         turn5+=termination_time-creation_time-sleeping_time;
                    }
                    
                    run_list[i]=running_time;
                    wait_list[i]=waiting_time;
                    create_list[i]=creation_time;
                    terminate_list[i]=termination_time;
                    sleeping_list[i]=sleeping_time;
                    
                }
            

        

           

            for (int i = 0; i < fork_num; i++)
                {
                    
                    run+=run_list[i];
                    wait+=wait_list[i];
                    turn+=terminate_list[i]-create_list[i]-sleeping_list[i];
                }
            
            

            printf(1,"\n\nprio=1 AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run6/5,wait6/5,turn6/5);
            printf(1,"\n\nprio=2 AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run1/5,wait1/5,turn1/5);
            printf(1,"\n\nprio=3 AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run2/5,wait2/5,turn2/5);
            printf(1,"\n\nprio=4 AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run3/5,wait3/5,turn3/5);
            printf(1,"\n\nprio=5 AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run4/5,wait4/5,turn4/5);
            printf(1,"\n\nprio=6 AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run5/5,wait5/5,turn5/5);
            printf(1,"\n\ntotal AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d\n\n \n",
                    run/fork_num,wait/fork_num,turn/fork_num);
            

        
        exit();
    }

