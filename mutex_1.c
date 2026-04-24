#include <stdio.h>
#include <pthread.h>

int acc_a = 1000000;
int acc_b = 1000000;

pthread_mutex_t mutex;

void* increase_counter_a_b(void* arg) 
{
    int i;
    for ( int i=0; i<1000000; i++) 
    {
        pthread_mutex_lock( &mutex ); 
      
        acc_a --;
        acc_b ++;
      
        pthread_mutex_unlock( &mutex ); 
    }
    pthread_exit( NULL );
}


int main() 
{
    pthread_t thread_1;
    

    pthread_mutex_init( &mutex, 0 );
    
    pthread_create(&thread_1, NULL, increase_counter_a_b, NULL);
 
    
    pthread_join(thread_1, NULL);
   
    

    pthread_mutex_destroy( &mutex );
    
    printf("El valor de acc_a es: %d\n", acc_a);
    printf("El valor de acc_b es: %d\n", acc_b);
    
    return 0;
}