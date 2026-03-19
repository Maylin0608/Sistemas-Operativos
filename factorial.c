#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int calcularFactorial(int numero){
    int res = 1;
    for(int i=1; i<=numero; i++){
        res = res * i;
    }
    return res;
}
    
int main()
{
    int numero, res, n, m;
    int status;
   
    
    printf("Ingrese el numero de m: " );\
    scanf("%d", &m);

    printf("Ingrese el numero de n: " );\
    scanf("%d", &n);
    
    pid_t pid_B, pid_C, pid_D;
    
    pid_B = fork();
    if(pid_B == 0) {
        int resultado = calcularFactorial(n - m);
        printf(" B: = %d\n", resultado);
        exit(resultado);
    }

    wait(&status);
    int res_B = WEXITSTATUS(status);

  
    pid_C = fork();
    if(pid_C == 0) {
        int resultado = calcularFactorial(m);
        printf(" C:  = %d\n", resultado);
        exit(resultado);
    }

    wait(&status);
    int res_C = WEXITSTATUS(status);

 
    pid_D = fork();
    if(pid_D == 0) {
        int resultado = calcularFactorial(n);
        printf(" D:  %d\n", resultado);
        exit(resultado);
    }

    wait(&status);
    int res_D = WEXITSTATUS(status);

  
    int resultado_final = res_D / (res_C * res_B);

    printf("Padre:  = %d\n", resultado_final);

    return 0;
}
   

   

  

