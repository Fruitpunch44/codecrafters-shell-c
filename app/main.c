#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define GENERAL_BUFF_SIZE 1024

void split_line(char *string);
void main_loop();

const char *built_ins[]={
      "echo",
      "exit",
      "type"
    };

char *get_env(char *path_loc){
  char *path=getenv("PATH");
  if(path==NULL){
    perror("error not found");
    return NULL;
  }
    strncpy(path_loc,path,GENERAL_BUFF_SIZE-1);
    return path_loc;
}

void handle_input(char *input){

  if(strcmp(input,"exit 0")==0){
    printf("exiting shell\n");
    exit(0);}
  else if(strncmp(input,"echo ",strlen("echo "))==0){
    printf("%s\n",input+strlen("echo "));}

  else if(strncmp(input,"type ",strlen("type "))==0){
    size_t length=sizeof(built_ins)/sizeof(built_ins[0]);
    char *arguments= input+strlen("type ");
    int built_in_found=0;

    for(size_t i=0;i<length;i++){
      if(strcmp(built_ins[i],arguments)==0){
        printf("%s is a builtin\n", arguments);
        built_in_found=1;
        break;
      }
    }
    if(built_in_found != 1){
      printf("%s: is not a built in\n",arguments);
    }
  }
  else{
    printf("invalid command try again\n");
  }
}

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  //create a loop to keep shell running until user exits
  while(1){
    printf("$eyi: ");
    char input[GENERAL_BUFF_SIZE];
    fgets(input, GENERAL_BUFF_SIZE, stdin);
    input[strlen(input) - 1] = '\0';
    handle_input(input);

}
return 0;
}
