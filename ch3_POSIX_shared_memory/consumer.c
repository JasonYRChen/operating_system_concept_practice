#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096;
    const char *name = "OS";
    
    int fd;
    char *pointer;

    fd = shm_open(name, O_RDONLY, 0666);
    pointer = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    printf("%s", (char *)pointer);

    shm_unlink(name);

    return 0;
}

