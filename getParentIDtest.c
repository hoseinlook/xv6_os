
#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"

int main(){
    
    
    

    for (int i=0;i<10;++i){
        
        int pid=fork();
        if (pid==0){
            sleep(50);
            printf(1,"  ****IN CHILD***\n");
            printf(1,"my pid  is %d\n",getpid());
            printf(1,"parent pid  is %d\n",getParentID());
            break;
        }
        else {
            printf(1,"  ****IN PARENT***\n");
            printf(1,"my pid  is %d\n",getpid());
            printf(1,"child pid  is %d\n",pid);
            wait();
        }
        printf(1,"****************************\n\n");
    }


exit();

}


