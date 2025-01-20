#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define buff_size 1024

char *return_reverse_string(char *string) {
    size_t length = strlen(string);
    char temp;
    for (size_t i = 0; i < length / 2; i++) {
        temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
    char *reversed = malloc(sizeof(char) * (length + 1));
    if (reversed == NULL) {
        printf("error allocating memory\n");
        return NULL;
    }
    strncpy(reversed, string, length);
    reversed[length] = '\0';
    return reversed;
}

int check(char *string1,char *revstring){
    if(strcmp(revstring,string1)==0){
         printf("%s is a palindrome of %s you dip\n",string1,revstring);
         return true;
    }
    return false;
}

int main() {
    char *word = malloc(sizeof(char) * buff_size);
       if (word == NULL) {
        perror("error in allocating memory");
        exit(1);
    }
    char *word_back_up=malloc(sizeof(char)*buff_size);
       if (word_back_up == NULL) {
        perror("error in allocating memory");
        exit(1);
    }
    printf("enter a word to check: ");
    fgets(word, buff_size, stdin);
    word[strcspn(word, "\n")] = '\0'; // Remove the newline character
    printf("word: %s\n", word);

    strncpy(word_back_up,word,strlen(word));
    char *return_me = return_reverse_string(word_back_up);
    if (return_me == NULL) {
        free(word);
        return 1;
    }
    printf("reverse: %s\n", return_me);

    check(word_back_up,return_me);

    free(word);
    free(return_me);
    free(word_back_up);
    return 0;
}
