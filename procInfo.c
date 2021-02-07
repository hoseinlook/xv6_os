#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]){
    

    
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    // printf(1,"ticks time =%d\n",test2());
    // printf(1,"running time =%d\n",test());
    
    int creation_time=1;
    int waiting_time=1;
    int running_time=1;
    int pid =0;
    for (int i =0 ; i<10 ; ++i){
        pid =fork();
        
        if (pid==0){
            for (int j = 0; j < 1000; j++)
            {
                printf(1,"pid=%d ,%d",getpid(),j);
            }
            exit();    
        }
        else{
            continue;
        }

    }
    int child_list[10];
    int run_list[10];
    int wait_list[10];
    int create_list[10];
   
    for (int i = 0; i <10 ; i++)
        {
            int child_ID=wait_and_get_info(&running_time,&waiting_time,&creation_time);
            child_list[i]=child_ID;
            run_list[i]=running_time;
            wait_list[i]=waiting_time;
            create_list[i]=creation_time;
            
        }
 printf(1,"*************************\n\n\n\n\n\n");
printf(1,"your pid =%d\n",getpid());

for (int i = 0; i < 10; i++)
{
    printf(1,"*************************\n\n\n");
   printf(1,"child=%d\n",child_list[i]);
            printf(1,"running_time = %d,waiting_time= %d ,creation_time = %d \n",
        run_list[i], wait_list[i],create_list[i]);
}

     
       
    exit();
    




}