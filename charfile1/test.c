      
#include <stdio.h>
#include <fcntl.h>

#define CHAR_DEVICE_NODE "/dev/demo_test"
#define BUF_SIZE 256
#define COMMAND_A 'a'
#define COMMAND_B 'b'

int main(void){
    int fd;
    int retval=0;
    char data_buf[BUF_SIZE]={0};

    //open
    fd = open(CHAR_DEVICE_NODE,O_RDWR);
    if(fd<0){
        printf("open %s failed!\n",CHAR_DEVICE_NODE);
        return -1;
    }
    printf(" open %s successfully!\n",CHAR_DEVICE_NODE);

    //read
    retval=read(fd,data_buf,16);
    if(retval<0){
        printf("read failed!\n");
        return -1;
    }
    printf("read %s successfully!\n",CHAR_DEVICE_NODE);

    //write
    retval=write(fd,"demo_test",10);
    if(!retval<0){
        printf("write failed!\n");
        return -1;
    }
    printf("write %s successfully!\n",CHAR_DEVICE_NODE);

    //lseek
    retval=lseek(fd,0,0);
    if(retval<0){
        printf("lseek failed!\n");
        return -1;
    }
    printf("lseek %s successfully!\n",CHAR_DEVICE_NODE);

    //ioctl
    retval=ioctl(fd,COMMAND_A,0);
    if(retval<0){
        printf("ioctl failed!\n");
        return -1;
    }
    printf("ioctl %s successfully(COMMAND_A)!\n",CHAR_DEVICE_NODE);

    close(fd);
    return 0;
}

    

