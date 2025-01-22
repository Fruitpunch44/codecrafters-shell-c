#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    //a way of creating processes in unix some what like threading i guess

    pid_t pid;//process id
    int i;
    char buf[400];

    fork();
    pid=getpid();
    for(i=1;i<=200;i++){
        snprintf(buf,1024,"the process pid is %d and value= %d\n",pid,i);
        fputs(buf,stdout);
        fflush(stdout);
    }

    
    return 0;
}