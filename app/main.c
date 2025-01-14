#include <stdio.h>
#include <string.h>

void split_line(char *string);
void main_loop();
void built_ins();

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  //create a loop to keep shell running until user exits
  while(1){
    printf("$ ");
    char input[100];
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';
    

    //break out of the loop
    if (strcmp(input, "exit 0")==0){
      return 0;}

    else if(strncmp(input,"echo",strlen("echo"))==0){
      printf("%s\n",input+strlen("echo")+1);
    }
  
    else if(strncmp(input,"type",strlen("type"))==0){
      char *built_in[]={
        "echo",
        "exit",
        "type"};
        size_t length=sizeof(built_in)/sizeof(built_in[0]);
        char *arguments= input+strlen("type")+1;

        int found_built_in=0;

        for(size_t i=0;i<length;i++){
          if(strcmp(built_in[i],arguments)==0){
            printf("%s is a shell builtin\n",arguments);
            found_built_in=1;
            break;
            }
        }
        if(found_built_in == 0){
          printf("%s: not found\n",arguments);
        }
        
    }
    else{
      printf("%s: command not found\n", input);
    }
  }
  return 0;
}