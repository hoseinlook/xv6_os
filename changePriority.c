#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]){
    
    
    if (argc<2){
        printf(1,"need to 2 arg \n");
        exit();
    }
    else{
       char number_char= *argv[1];
       int num =(int )number_char -48;
       printf(1,"your number is %d\n",num);
       int new_policy=changePriority(num);
       if (new_policy == -1){
           printf(1,"your policy number  must be between 1 and 6\n");
           exit();
       }
       printf(1," success! new_priority is %d\n",new_policy);
       
       
       exit();
    }




}