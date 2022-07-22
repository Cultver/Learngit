//
// Created by ts on 2022/7/21.
//
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <syslog.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>

#define MAX_DATA_LEN 256
#define DELAY_TIME 1

int main(){
    pid_t pid;
    int pipe_fd[2];
    char buf[MAX_DATA_LEN];
    const char data[]="Pipe Test Program";
    int real_read,real_write;

    memset((void*)buf,0,sizeof(buf));
    if(pipe(pipe_fd)<0){
        printf("Pipe create error\n");
        exit(1);
    }
    if((pid=fork())==0){//child
        close(pipe_fd[1]);
        sleep(DELAY_TIME * 5);
        if(0<(real_read= read(pipe_fd[0],buf,MAX_DATA_LEN))){
            printf("I am child progress.I have read %d bytes from the pipe:'%s'\n",real_read,buf);
        }
        close(pipe_fd[0]);
        exit(0);
    } else if(pid>0){//parent
        close(pipe_fd[0]);
        sleep(DELAY_TIME);
        if((real_write= write(pipe_fd[1],data, strlen(data)))!=-1){
            printf("I am parent progress. I have wrote %d bytes to the pipe:'%s'\n",real_write,data);
        }
        close(pipe_fd[1]);
        waitpid(pid,NULL,0);
	printf("parent progress exit\n");
        exit(0);

    }
}
