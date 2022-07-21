//
// Created by ts on 2022/7/21.
//
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <syslog.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/stat.h>
void init_daemon(){
    int pid;
    int i;
    printf("init_daemon()\n");
    openlog("init_daemon log",LOG_PID,LOG_DAEMON);

    if(0 < (pid=fork())){
	printf("parent process exit.\n");
        exit(0);
    }else if(0>pid){
	printf("create daemon fail.");
        syslog(LOG_INFO,"create daemon fail.");
        exit(-1);
    }
    setsid();//create new session and group,disconnect terminal
    chdir("/tmp");//change work dir
    umask(0);//clear umask
    for (i = 0; i < NOFILE; ++i) {//closes STDIN STDOUT STDERR
        close(i);
    }
    syslog(LOG_INFO,"create daemon sucess.");
}
