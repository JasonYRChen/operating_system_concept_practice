#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096;
    const char *name = "OS";
    const char *msg1 = "Hello";
    const char *msg2 = "world";

    int fd;
    char *pointer;

    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    pointer = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    sprintf(pointer, "%s", msg1);
    pointer += strlen(msg1);
    sprintf(pointer, "%s", msg2);
    pointer += strlen(msg2);

    return 0;
}

