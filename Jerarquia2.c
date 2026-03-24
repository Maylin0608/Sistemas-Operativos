#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
        
        
        
int main ()
{
        
    int status;
    pid_t pid_B, pid_C, pid_E;
        
    pid_B = fork();
        
    if( pid_B == 0){
     sleep(3);
     exit(1);
}
            
        
pid_C = fork();
        
if(pid_C == 0){
    sleep(1);
    exit(2);
}
            
pid_E = fork();
        
if(pid_E == 0){
exit(3);
}
            
                

waitpid(pid_B, &status, 0);
printf(" %d\n", WEXITSTATUS(status));

        

waitpid(pid_C, &status, 0);
printf(" %d\n", WEXITSTATUS(status));

        

        
waitpid(pid_E, &status, 0);
printf(" %d\n", WEXITSTATUS(status));

                
                
                
}
    
        
        
        