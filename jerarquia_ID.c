#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    pid_t T, W, V, S, L, P;

    printf("Proceso R  PID: %d Padre: %d\n", getpid(), getppid());

    T = fork();

    if (T == 0) {  

        printf("Proceso T  PID: %d Padre: %d\n", getpid(), getppid());

        V = fork();

        if (V == 0) {
            printf("Proceso V  PID: %d Padre: %d\n", getpid(), getppid());
        }

    }
    else {

        W = fork();

        if (W == 0) {   
            

            printf("Proceso W  PID: %d Padre: %d\n", getpid(), getppid());

            S = fork();

            if (S == 0) {

                printf("Proceso S  PID: %d Padre: %d\n", getpid(), getppid());

                L = fork();

                if (L == 0) {

                    printf("Proceso L  PID: %d Padre: %d\n", getpid(), getppid());

                    P = fork();

                    if (P == 0) {
                        printf("Proceso P  PID: %d Padre: %d\n", getpid(), getppid());
                    }

                }

            }

        }

    }

    return 0;
}