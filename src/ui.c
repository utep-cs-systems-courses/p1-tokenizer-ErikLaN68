#include "stdio.h"
#include "user.h"
#include "token.h"

int main(int argc, char **argv)
{
  printf("--The program name is <%s>\n--", *(argv+0));
  puts("Welcome to the Tokenizer");
  fputs("Enter a string to be tokenized\n--COMMANDS--\nEnter history to see pervious inputs\nEnter exit to end the program\n",stdout);
  // makes the userString to take input
  char userString[MAX];
  
  while (1) {
    
    fputs("> ",stdout);
    fgets(userString,sizeof(userString),stdin);
    printf("echo %s", userString);

    // pointer that points to the user input
    char *pUser = userString;
    user_remove_newline(pUser);

    // compares user input to "history" to view old inputs
    if (user_strcmp(pUser,pHis) == 0) {
	printf("will print history\n");
      }

    // compares user input to "exit" to leave the program
    else if (user_strcmp(pUser,pExit) == 0) {
      puts("Thanks for using the program");
      goto done;
      }
    
    else {
      puts("Will be tokenized");
      printf("The number of tokens in the input is %d", count_tokens(pUser));
      goto done;
    }
    
  }
  done:
    return 0;
}
