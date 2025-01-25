#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <fcntl.h>
#include<unistd.h>
#include<sys/types.h>

#define GENERAL_BUFF_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"

//implement later 
char **split_line(char *string){
  int buffer=GENERAL_BUFF_SIZE;
  char *TOKEN;
  int position=0;
  char **tokens=malloc(buffer*sizeof(char));
  if(tokens==NULL){
    perror("error allocating memory for the buffer");
  }
  TOKEN=strtok(string,TOKEN_DELIM);
  while (TOKEN != NULL)
  {
    tokens[position]=TOKEN;
    position++;
  
  //not actually possible 
  if(position >= buffer){
    buffer +=GENERAL_BUFF_SIZE;
    tokens=realloc(tokens,buffer*sizeof(char));
    if(tokens==NULL){
      perror("Error reallocating memmory");
    }
  }
  TOKEN=strtok(NULL,TOKEN_DELIM);
  }
 
  tokens[position]=NULL;
  return tokens;
  
}

void main_loop();//implement later

const char *built_ins[]={
      "echo",
      "exit",
      "type",
    };
int check_executable(const char *path){
   return access(path, X_OK) == 0;
}

char *find_in_path(char *arguments){
  char *path=getenv("PATH");
  if(path==NULL){
    perror("error not found");
    return NULL;
  }

  char *path_buffer=malloc(sizeof(char)*strlen(path)+1);
    strncpy(path_buffer,path,strlen(path)+1);
    char *full_path=malloc(sizeof(char)*GENERAL_BUFF_SIZE);
    if(full_path==NULL){
      perror("error in allocation");
      free(path_buffer);
      exit(1);
    }

    char *DIR = strtok(path_buffer,":");
    while( DIR != NULL){
      snprintf(full_path,GENERAL_BUFF_SIZE,"%s/%s",DIR,arguments);
      if(check_executable(full_path)){
        free(path_buffer);
        return full_path;
      }
        DIR=strtok(NULL,":");
    }
    
    free(path_buffer);
    free(full_path);
    return NULL;
}

int check_for_built_in(char *arguments){
  size_t length=sizeof(built_ins)/sizeof(built_ins[0]);

    for(size_t i=0;i<length;i++){
      if(strcmp(built_ins[i],arguments)==0){
        printf("%s is a shell builtin\n", arguments);
        return 1;
      }
    }
    return 0;

}

void execute_program(char *path,char **arguments){
  pid_t pid,pid2;//one for the fork process and another to return the process id
  pid=fork();
  pid2=getpid();
  if(pid==0){
    execv(path,arguments);
    //execv doesn't return anything
    perror("no such directory");
    exit(1);
  }

}
void handle_input(char *input){
  char *arguments=input;

  if(strcmp(input,"exit 0")==0){
    exit(0);
    }
  else if(strncmp(input,"echo ",strlen("echo "))==0){
    printf("%s\n",input+strlen("echo "));}

  else if(strncmp(input,"type ",strlen("type "))==0){

    char *arguments= input+strlen("type ");
    if(check_for_built_in(arguments)){
      return;
    }
    char* path=find_in_path(arguments);
    if(path){
      printf("%s is %s\n",arguments,path);
    }
    else{
      printf("%s: not found\n",arguments);
    }
  }
  else if(check_for_built_in(arguments)==0){
    char **args=split_line(input);
    /*printf("commands \n");
    for (int i = 0; args[i] != NULL; i++) {
      printf("%s\n", args[i]);}*/

    char *path=find_in_path(arguments);
    execute_program(path,args);
  }
  else{
    printf("%s: command not found\n",input);
  }
}

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  //create a loop to keep shell running until user exits
  while(1){
    printf("$ ");
    char input[GENERAL_BUFF_SIZE];
    fgets(input, GENERAL_BUFF_SIZE, stdin);
    input[strlen(input) - 1] = '\0';
    handle_input(input);

}
return 0;
}
