#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]){
    
    


       printf(1,"my priority =%d\n",get_priority());
       printf(1,"change prioriy to 5\n");
       changePriority(5);
       printf(1,"my priority =%d\n",get_priority());

       
       exit();
    




}