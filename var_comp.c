#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int key_1 = 0;
int key_2 = 0;

pthread_mutex_t mutex;
pthread_cond_t cond_consumer, cond_producer;

void* producer(void* arg)
{
    
        pthread_mutex_lock( &mutex );
       
        key_1 = 1;
        printf("La llave 1 a llegado a 1\n");
            
        pthread_cond_signal( &cond_consumer );
        pthread_mutex_unlock( &mutex );
    

    pthread_exit( NULL );
}

void* consumer(void* arg)
{
    
        pthread_mutex_lock( &mutex );
   
        while (key_1 == 0) 
        {
     
            pthread_cond_wait( &cond_consumer, &mutex );
        }
        printf("Ahora llave 2 esta en 1 .\n");
        key_2 = 1;
        
   
        pthread_cond_signal( &cond_producer ); 
        pthread_mutex_unlock( &mutex );
        
    

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_1, thread_2;

    
    
    pthread_mutex_init( &mutex, 0 );
    pthread_cond_init( &cond_consumer, 0 );
    pthread_cond_init( &cond_producer, 0 );
    
 
    pthread_create( &thread_1, NULL, producer, NULL );
    pthread_create( &thread_2, NULL, consumer, NULL );
    
    pthread_join( thread_1, NULL);
    pthread_join( thread_2, NULL);

    if(key_1 == 1 && key_2 == 1 ){
        printf("El cohete a sido lanzado\n");
    }

    pthread_mutex_destroy( &mutex );
    pthread_cond_destroy( &cond_consumer );
    pthread_cond_destroy( &cond_producer );
    
    return 0;
}