#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(void)
{
    int i;
    int fd;

    printf("File attack test starting\n");

    for(i = 0; i < 50; i++) {
        fd = open("README", O_RDONLY);
        if(fd >= 0)
            close(fd);
    }

    printf("File attack test completed\n");
    exit(0);
}