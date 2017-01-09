#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


#define FIFONAME "MY_FIFO"

int ReadIpcFileValue (const char *filename, char *value, int valueSize )
{
    static int idx=0;
    printf("before read %d\n",idx++);
    int fd;

    /* write "Hi" to the FIFO */
    fd = open(filename, O_RDONLY| O_NONBLOCK );


    int result = read(fd, value, valueSize);
    printf("after read [%s]\n",value);
    close(fd);

}

char tmp[100];
int main(){
    while(1){
        ReadIpcFileValue(FIFONAME,tmp,sizeof(tmp));
        sleep(1);
    }
}
