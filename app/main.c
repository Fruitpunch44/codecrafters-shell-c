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
    
    printf("%s: command not found\n", input);

    //break out of the loop
    if (strcmp(input, "exit 0")==0){
      printf("Goodbye cruel world!\n");
      exit(0);
    }
  }
  return 0;
}