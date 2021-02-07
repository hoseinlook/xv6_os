#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"



int main(int argc, char *argv[]){
    
    
       
       int num =atoi(argv[1]);
       
       int result = changeQuantum(num);
       printf(1," success! new quantom is %d\n",result);
       
       exit();
    

}