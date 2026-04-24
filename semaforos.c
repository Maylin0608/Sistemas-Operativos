#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int active_connections = 0;
sem_t semaphore_id;


void* estado_base_datos(void* arg) {

    sem_wait(&semaphore_id);  

    active_connections++;
    printf("Conexiones activas: %d\n", active_connections);
    sleep(1);  
    active_connections--;

    sem_post(&semaphore_id);  

    return NULL;
}

int main() {
    pthread_t threads[10];


    sem_init(&semaphore_id, 0, 3);


    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, estado_base_datos, NULL);
    }

   
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

  
    sem_destroy(&semaphore_id);


    printf("Conexiones activas finales: %d\n", active_connections);

    return 0;
}