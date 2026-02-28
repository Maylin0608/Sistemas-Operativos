#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


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


void escribirDatos() {

    float arreglo[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    int fd = open("datos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    verificarError(fd);

    int n = write(fd, arreglo, sizeof(arreglo));
    verificarError(n);

    close(fd);
}


void leerDatos() {

    float arreglo[5];

    int fd = open("datos.txt", O_RDONLY);
    verificarError(fd);

    int n = read(fd, arreglo, sizeof(arreglo));
    verificarError(n);

    printf("\nContenido de datos.txt:\n");

    for (int i = 0; i < 5; i++) {
        printf("%.2f\n", arreglo[i]);
    }

    close(fd);
}


void escribirDatos2() {

    float valores[5] = {10.5, 20.5, 30.5, 40.5, 50.5};

    int fd = open("datos2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    verificarError(fd);

    for (int i = 0; i < 5; i++) {

        int n = write(fd, &valores[i], sizeof(float));
        verificarError(n);

        printf("Escribiendo %.2f -> n = %d\n", valores[i], n);
    }

    close(fd);
}


void leerDatos2() {

    float valor;

    int fd = open("datos2.txt", O_RDONLY);
    verificarError(fd);

    printf("\nContenido de datos2.txt:\n");

    while (read(fd, &valor, sizeof(float)) > 0) {
        printf("%.2f\n", valor);
    }

    close(fd);
}


void moverCerosIzquierda(int arr[], int size) {

    int temp[size];
    int index = 0;

   
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            temp[index++] = 0;
        }
    }

   
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            temp[index++] = arr[i];
        }
    }

   
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}


int main() {

    escribirDatos();
    leerDatos();

    escribirDatos2();
    leerDatos2();

    int arreglo[10] = {1, 2, 0, 4, 9, 0, 3, 5, 1, 3};

    moverCerosIzquierda(arreglo, 10);

    printf("\nArreglo con ceros a la izquierda:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", arreglo[i]);
    }

    printf("\n");

    return 0;
}