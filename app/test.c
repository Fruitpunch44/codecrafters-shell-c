#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GENERAL_BUFF_SIZE 1024

const char *built_ins[] = {
    "echo",
    "exit",
    "type"
};

char *get_env(char *path_loc) {
    char *path = getenv("PATH");
    if (path == NULL) {
        perror("Error: PATH environment variable not found");
        return NULL;
    }
    strncpy(path_loc, path, GENERAL_BUFF_SIZE - 1);
    path_loc[GENERAL_BUFF_SIZE - 1] = '\0'; // Ensure null termination
    return path_loc;
}

void handle_input(char *input) {
    if (strcmp(input, "exit 0") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    } 
    else if (strncmp(input, "echo ", strlen("echo ")) == 0) {
        printf("%s\n", input + strlen("echo "));
    } else if (strncmp(input, "type ", strlen("type ")) == 0) {
        size_t length = sizeof(built_ins) / sizeof(built_ins[0]);
        char *arguments = input + strlen("type ");
        int built_in_found = 0;

        for (size_t i = 0; i < length; i++) {
            if (strcmp(built_ins[i], arguments) == 0) {
                printf("%s is a built-in command.\n", arguments);
                built_in_found = 1;
                break;
            }
        }

        if (!built_in_found) {
            printf("%s: is not a built-in command.\n", arguments);
        }
    } else {
        printf("Invalid command. Please try again.\n");
    }
}

int main() {
    // Flush after every printf
    setbuf(stdout, NULL);

    while (1) {
        printf("$eyi: ");
        char input[GENERAL_BUFF_SIZE];
        
        if (fgets(input, GENERAL_BUFF_SIZE, stdin) == NULL) {
            printf("\nExiting...\n");
            break;
        }

        // Safely remove trailing newline if present
        input[strcspn(input, "\n")] = '\0';

        handle_input(input);
    }

    return 0;
}
