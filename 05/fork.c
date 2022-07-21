//
// Created by ts on 2022/7/21.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int pid1 = fork();

    if(0==pid1){
        int pid2 = fork();
        if(0==pid2){
            printf("child 2, pid2:%d\n",pid2);
            sleep(15);
            printf("child 2 finish\n");
        }else{
            printf("child 1,child 2 pid:%d\n",pid2);
            sleep(1);
            printf("child 1 finish\n");
        }
    }else{
        printf("parent 1,child 1 pid:%d\n",pid1);
    }
    return 0;
}
