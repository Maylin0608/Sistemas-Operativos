#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void señal_alarma(int sig)
{
  printf("Transcurrieron los 3 segundos\n");
 
}
 
int main()
{ 

  signal(SIGALRM,señal_alarma); 
 
    alarm(3);

    pause();
  
  return 0;
}
