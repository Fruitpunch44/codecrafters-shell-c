#include <stdio.h>
#include <string.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  //create a loop to keep shell running until user exits
  while(1){
    printf("$ ");

    // Wait for user input
    char input[100];
    fgets(input, 100, stdin);

    // Remove the trailing newline
    input[strlen(input) - 1] = '\0';
    

    //break out of the loop
    if (strcmp(input, "exit 0")==0){
      exit(0);}
    else if(strcmp(input,"echo %s")==0){
      printf("%s\n",input);
    }
     printf("%s: command not found\n", input);
  }
  return 0;
}