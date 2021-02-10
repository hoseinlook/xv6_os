#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]){
    
    
     for (int i=0;i<100;++i)
        printf(1,"counter =%d\n",test());
    sleep(2000);
    printf(1,"counter =%d\n",test2());
                                      

    // int creation_time=1;
    // int waiting_time=1;
    // int running_time=1;
    // int termination_time=1;
    // int sleeping_time=1;
    // int pid =0;
    // for (int i =0 ; i<10 ; ++i){
    //     pid =fork();
        
    //     if (pid==0){
    //         for (int j = 0; j < 1000; j++)
    //         {
    //             printf(1,"pid=%d ,%d",getpid(),j);
    //         }
    //         exit();    
    //     }
    //     else{
    //         continue;
    //     }

    // }
    // int child_list[10];
    // int run_list[10];
    // int wait_list[10];
    // int create_list[10];
    // int terminate_list[10];
    // int sleeping_list[10];
   
    // for (int i = 0; i <10 ; i++)
    //     {
    //         int child_ID=wait_and_get_info(&running_time,&waiting_time,&creation_time,&termination_time,&sleeping_time);
    //         child_list[i]=child_ID;
    //         run_list[i]=running_time;
    //         wait_list[i]=waiting_time;
    //         create_list[i]=creation_time;
    //         terminate_list[i]=termination_time;
    //         sleeping_list[i]=sleeping_time;
            
    //     }
    // printf(1,"*************************\n\n\n\n\n\n");
    // printf(1,"your pid =%d\n",getpid());

    // for (int i = 0; i < 10; i++)
    //      {
    //         printf(1,"*************************\n\n\n");
    //         printf(1,"child=%d\n",child_list[i]);
    //         printf(1,"running_time = %d,waiting_time= %d ,creation_time = %d , terminate=%d , sleep=%d \n",
    //             run_list[i], wait_list[i],create_list[i],terminate_list[i],sleeping_list[i]);
    //      }

    // int run=0;
    // int wait=0;
    // int turn=0;

    // for (int i = 0; i < 10; i++)
    //      {
    //         run+=run_list[i];
    //         wait+=wait_list[i];
    //         turn+=terminate_list[i]-create_list[i]-sleeping_list[i];
    //      }
    
    // printf(1,"AVGrunning_time = %d,AVGwaiting_time= %d ,AVGturnAround =%d \n",
    //           run/10,wait/10,turn/10);



     
       
    exit();
    
}