#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <sys/wait.h>
#include <stdlib.h>

void handler_alarm(int sig){
    printf("Alarma recibida \n");
    fflush(stdout);
}


    int main(){

    int status;
    pid_t pid_B, pid_C ;

    pid_B = fork();


    if (pid_B == 0) {  
        sleep(1);
          
    pid_C = fork();

        if (pid_C == 0) {
            while (1){
                printf("Esperando una señal\n");
                fflush(stdout);
            } 
        }
   
        sleep(1);
        kill(pid_C, SIGKILL);
        
        pause();

        exit(0);
  

    }
  
    signal(SIGALRM, handler_alarm);
    alarm(5);
    
    wait(NULL); 

return 0;
    
    }

 
    
    
    
    
    
    
    
    
    
    
    
    
    
