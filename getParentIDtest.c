
#include "types.h"
#include "stat.h"
#include "user.h"


int main(){
    
    


    for (int i=0;i<10;++i){
        
        int pid=fork();
        if (pid==0){
            
            printf(1,"my pid  is %d",getpid());
            printf(1,"parent pid  is %d",getParentID());
            break;
        }
        else {
            printf(1,"my pid  is %d",getpid());
            printf(1,"child pid  is %d",pid);
            wait();
        }
        printf(1,"****************************\n\n");
    }


exit();

}


