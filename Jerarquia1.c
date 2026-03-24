#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>



    int main ()
{

    int status;
    pid_t pid_L, pid_D = -1;

    pid_L = fork();

    if( pid_L == 0){
        printf("Termine mi ejecucion %d y el pid de mi padre es %d\n",getpid(),getppid());
        sleep(3);
        exit(0);
    }
    

    pid_D = fork();

    if(pid_D == 0){
        printf("Termine mi ejecucion %d y el pid de mi padre es %d\n", getpid(), getppid());
        sleep(1);
        exit(0);
    }
    
    
    else{
        
        wait(&status);

        printf("Uno de mis hijos a terminado su ejecucion \n");
    
    return 0;

}
}