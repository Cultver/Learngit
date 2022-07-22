//
// Created by ts on 2022/7/22.
//
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define FIFO_NAME "myfifo"
#define FILEMODE (S_IRUSR |  S_IWUSR)

int main(){
    char r_buf[50];
    int fd;
    int r_num;

    if(access(FIFO_NAME,R_OK)<0){
        printf("cannot read fifo...\n");
        return 1;
    }
    fd = open(FIFO_NAME,O_RDONLY);
    if(fd==-1){
        printf("open %s for read error\n",FIFO_NAME);
        return 1;
    }

    r_num = read(fd,r_buf,6);
    printf("Get %d bytes \"%s\"from %s\n",r_num,r_buf,FIFO_NAME);
    close(fd);
    sleep(15);
    unlink(FIFO_NAME);

    return 0;
}
