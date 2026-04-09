#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include <sys/wait.h>
#include <stdlib.h>


void signal_handler_sigusr1(int sig){
    printf("Recibi la señal SIGUSR1, Mi PID ES: %d y el de mi padre es: %d\n", getpid(), getppid());
    }

void signal_handler_sigusr2(int sig){
    printf("Recibi la señal SIGUSR2, Mi PID es: %d y el de mi padre es: %d\n", getpid(), getppid());
}
void handler_alarm(int sig){
    printf("Alarma recibida \n");
}


    int main(){

    int status;
    pid_t pid_A, pid_C ;

    pid_A = fork();


    if (pid_A == 0) {  
        signal(SIGUSR1,signal_handler_sigusr1); 
          
    pid_C = fork();

        if (pid_C == 0) {
            signal(SIGUSR2,signal_handler_sigusr2); 
            pause();
            exit(0);  
        }
    
    pause();
    sleep(1);
    kill(pid_C, SIGUSR2);

    wait(NULL);
    exit(0);

    }
    
    signal(SIGALRM, handler_alarm);
    alarm(3);

    pause();  

    sleep(1); 
    kill(pid_A, SIGUSR1);

    wait(NULL); 

    printf("Mis hijos han terminado\n");

    return 0;
    

    
    }

 
    
    
    
    
    
    
    
    
    
    
    
    
    
