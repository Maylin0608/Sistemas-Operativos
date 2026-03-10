#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>


int main() {

    int numero_1, numero_2, numero_3;
    pid_t A = -1, B =-1, M = -1;
    int status;
    int hijos_correctos = 0;


    srand(time(NULL));
    numero_1 = rand() % 11;
    numero_2 = rand() % 11;
    numero_3 = rand() % 11;

    

    A = fork();

    if (A == 0) {  
         printf(" El PID de A:%d  y su numero es:%d\n",  getpid(), numero_1 );
        exit(0);
    }    
    
     B = fork();

    if (B == 0) {
         printf("El PID de B: %d  y su numero es:%d\n", getpid(), numero_2 );
         exit(0);
        }

       
        M = fork();
        if (M == 0) {
        printf(" El PID de M:%d   y su nuemro es %d\n",  getpid(), numero_3 );
        exit(0);
        }

        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            hijos_correctos++;
    
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            hijos_correctos++;
    
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
            hijos_correctos++;
    
        printf("Hijos que terminaron correctamente: %d\n", hijos_correctos);
    
        return 0;
    }

   
