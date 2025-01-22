#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

/*it's good to know that u*/


int main(){
    pid_t pid;
    int n;
    pid=fork();
    if(pid==0){
        n=1;
    }
    else{
        n=6;
    }
    int i;
    for (i=n; i<n+5; i++){
        printf("%d",i);
        fflush(stdout);
    }
    printf("\n");
    return 0;
}
