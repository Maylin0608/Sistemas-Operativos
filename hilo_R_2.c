#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void señal_sigint(int sig)
{
  printf("El usuario a presionado CTRL+C\n");
  sleep(3);
}
 
int main()
{ 
  signal(SIGINT,señal_sigint); 
 
 while(1) {
    printf("Su PID es: %d\n", getpid());
    sleep(1);
  
  }
  return 0;
}
