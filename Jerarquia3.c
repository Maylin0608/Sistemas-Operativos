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
    pid_t A,B,C,D;
        
    A = fork();
        
    if( A == 0){
     printf("Mi nombre es A y mi pid es: %d y el de mi padre es: %d\n", getpid(), getppid());
  
            
    D = fork();
        
    if(D == 0){
    printf("Mi nombre es D y mi pid es: %d y el de mi padres es: %d\n", getpid(), getppid());
    execl("/bin/ls", "ls",  NULL);

    }else{
    wait (NULL);
    execl("/bin/rm", "rm", "-r", "new_folder", NULL);
} 
    } 

if(A>0){

B = fork();
        
if(B == 0){
    printf("Mi nombre es B y mi pid es:  %d y el de mi padre es: %d\n", getpid(), getppid());
    execl("/bin/mkdir", "mkdir", "new_folder", NULL);
  
}
            
C = fork();
        
if(C == 0){
    printf("Mi nombre es C y mi pid es: %d y el de mi padres es: %d\n", getpid(), getppid());
    execl("/bin/ls", "ls",  NULL);

}

              

waitpid(A, &status, 0);

waitpid(C, &status, 0);

waitpid(B, &status, 0);

printf("mi nombre es M y mi pid es: %d\n", getpid());
execl("/bin/ls", "ls", NULL);

}  
           
return 0;              
                
}


        
        
        