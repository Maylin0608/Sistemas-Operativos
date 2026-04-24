#include <stdio.h>
#include <pthread.h>

#define b 1000

int current_i = 0;
int buffer_index = 0;
int buffer[b];

pthread_mutex_t mutex;


void* aumento_buffer(void* arg) {
    
    pthread_mutex_lock(&mutex);  

    buffer[buffer_index] = current_i;
    buffer_index++;
    current_i++;

    pthread_mutex_unlock(&mutex); 

    return NULL;
}

int main() {
    pthread_t threads[b];

    pthread_mutex_init(&mutex, NULL);


    for (int i = 0; i < b; i++) {
        pthread_create(&threads[i], NULL, aumento_buffer, NULL);
    }

  
    for (int i = 0; i < b; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

 

    for (int i = 0; i < b; i++) {
        if (buffer[i] == 0) {
            printf(" buffer en %d es igual a 0\n", i);
        }
    }

    return 0;
}