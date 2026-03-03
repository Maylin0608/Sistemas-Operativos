#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>



void verificarError(int valor) {

    if (valor < 0) {

        if (errno == EAGAIN) {
            printf("Error EAGAIN: Recurso temporalmente no disponible.\n");
        }

        else if (errno == EACCES) {
            printf("Error EACCES: Permiso denegado.\n");

        }

        else if (errno == EBADF) {
            printf("Error EBADF: Descriptor inválido.\n");
        }

        else {
            perror("Error detectado");
        }

        exit(EXIT_FAILURE);
    }
}



void escribirEnteros() {

    int arreglo[5] = {1, 2, 3, 4, 5};

    int fd = open("datos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    verificarError(fd);

    int n = write(fd, arreglo, sizeof(arreglo));
    verificarError(n);

    close(fd);
}


void leerEnteros() {

    int arreglo[5];

    int fd = open("datos.txt", O_RDONLY);
    verificarError(fd);

    int n = read(fd, arreglo, sizeof(arreglo));
    verificarError(n);
    
    printf("\nContenido de datos.txt:\n");
    for (int i = 0; i<5; i++){
        printf("%d\n", arreglo[i]);
    }

    close(fd);
}



int main ()
{

    pid_t pid_q, pid_m = -1;

    pid_m = fork();

    if( pid_m == 0){
        printf("El hijo m escribe los enteros \n");
        escribirEnteros();
    }
    else{
        sleep(3);
        printf("El padre q lee e imprime \n");
        leerEnteros();
    }
    

}