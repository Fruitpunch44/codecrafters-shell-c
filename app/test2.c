#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 3000


int main(){ 
char *path = getenv("PATH");
if(path ==NULL){
    perror("could not locate path");
}
char *split;
 /* get only the 1st token */
split=strtok(path,":");

 /* walk through other tokens */
while(split !=NULL){
    printf("%s \n",split);
    split=strtok(NULL,":");
}
return 0;
}