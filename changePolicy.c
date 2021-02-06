
#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"



int main(int argc, char *argv[]){
    
    
    if (argc<2){
        printf(1,"enter a number between 0 and 2\n");
        exit();
    }
    else{
       char number_char= *argv[1];
       int num =(int )number_char -48;
       printf(1,"your number is %d\n",num);
       int new_policy=changePolicy(num);
       if (new_policy == -1){
           printf(1,"your policy number  must be 1 or 2 or 0\n");
           exit();
       }
       printf(1," success! new_policy is %d\n",new_policy);
       
       exit();
    }




}


