#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i, j;
    
    for (i = 0; i < 5; i++) {
        pid = fork();
        
        if (pid == 0) {
            if (i % 2 == 0) {
                for (j = 0; j < 4; j++) {
                    pid_t sub_pid = fork();
                    if (sub_pid == 0) {
                        printf("I am sub-child %d of child %d\n", j, i);
                        exit(0);
                    }
                }
                for (j = 0; j < 4; j++) {
                    wait(NULL);
                }
            } else {
                for (j = 0; j < 5; j++) {
                    pid_t sub_pid = fork();
                    if (sub_pid == 0) {
                        printf("I am sub-child %d of child %d\n", j, i);
                        exit(0);
                    }
                }
                for (j = 0; j < 5; j++) {
                    wait(NULL);
                }
            }
            printf("I am child %d\n", i);
            exit(0);
        } else if (pid < 0) {
            printf("Fork failed for child %d\n", i);
            exit(1);
        }
    }
    
    for (i = 0; i < 5; i++) {
        wait(NULL);
    }
    
    printf("I am parent\n");
    
    return 0;
}
