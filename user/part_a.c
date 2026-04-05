#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[])
{

    int pid = fork();
    int fd = open("abc.txt", O_CREATE);
    close(fd);
    mkdir("files");
    if (pid > 0)
    {

        // do nothing
    }
    else if (pid == 0)
    {

        char *argvv[2];
        argvv[0] = "ls";
        argvv[1] = 0;
        exec("ls", argvv);
        exit(0);
    }
    else
    {
        printf("fork error\n");
    }

    exit(0);
}