#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void error(char *msg)
{
     fprintf(stderr, "%s: %s\n", strerror(errno), msg);
     exit(1);
}

int main()
{
    pid_t pid[2];
    char *program[] = {"./producer", "./consumer"};
    int i, pid_status;

    for (i = 0; i < 2; i++){
        pid[i] = fork();
        if (pid[i] == -1)
            error("Fork failed");
        if (!pid[i]) {
            execl(program[i], program[i], NULL);
            error("Child process error");
        }
        sleep(1);
    }

    for (i = 0; i < 2; i++) {
        if (waitpid(pid[i], &pid_status, 0) == -1)
            error("Error for waiting child process.");
        printf("process %i terminated, status: %i\n", pid[i], pid_status);
    }

    return 0;
}

