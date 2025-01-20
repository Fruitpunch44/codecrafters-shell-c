#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define buff_size 1024

char *getpath(){
    char *path=getenv("PATH");
    char *paths=malloc(sizeof(char)* strlen(path)+1);
    if(paths==NULL){
        perror("error in allocating memory");
        exit(1);
    }
    strncpy(paths,path,strlen(path)+1);
    return paths;
}

int main(){
    char *some=getpath();
    printf("%s",some);
    free(some);
    return 0;
}