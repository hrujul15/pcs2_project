#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int main(int argc, char *argv[])
{
    
    int fd = open("abc.txt", O_CREATE | O_RDWR);
    if(fd >= 0) {
        close(fd);
    }
    mkdir("files");

  
    int pid = fork();

    if (pid > 0)
    {
       
        wait(0);
    }
    else if (pid == 0)
    {
        
        char *argvv[2];
        argvv[0] = "ls";
        argvv[1] = 0;
        exec("ls", argvv);
        
        
        
        exit(1);
    }
    else
    {
        printf("fork error\n");
    }

    exit(0);
}
