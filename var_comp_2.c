#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 1;
int even_turn = 0; 

pthread_mutex_t mutex;
pthread_cond_t cond;

void* imprime_impares(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        while (even_turn == 1)
            pthread_cond_wait(&cond, &mutex);

        if (counter > 100) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("Hilo impar: %d\n", counter);
        counter++;

        even_turn = 1;

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* imprime_pares(void* arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        while (even_turn == 0)
            pthread_cond_wait(&cond, &mutex);

        if (counter > 100) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("Hilo par: %d\n", counter);
        counter++;

        even_turn = 0;

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, imprime_impares, NULL);
    pthread_create(&t2, NULL, imprime_pares, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}