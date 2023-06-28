#include "stdio.h"
#include "user.h"
#include "token.h"
#include "history.h"

int main(int argc, char **argv)
{
  printf("The program name is <%s>\n", *(argv+0));
  puts("--Welcome to the Tokenizer--");
  fputs("Enter a string to be tokenized\n--COMMANDS--\nEnter history to see pervious inputs\nEnter exit to end the program\n",stdout);
  
  // makes the userString to take input
  char userString[MAX];
  // list used for history
  //List linkList;
  //linkList.root = NULL;
  List *linkList = init_history();
    
  while (1) {
    fputs("> ",stdout);
    fgets(userString,sizeof(userString),stdin);
    //printf("%s", userString);

    // pointer that points to the user input
    char *pUser = userString;
    user_remove_newline(pUser);

    // compares user input to "history" to view old inputs
    if (user_strcmp(pUser,pHis) == 0) {
      print_history(linkList);
      }

    // compares user input to "exit" to leave the program
    else if (user_strcmp(pUser,pExit) == 0) {
      puts("Thanks for using the program");
      goto done;
      }
    
    else {
      //prints number of tokens
      printf("The number of tokens in the input is %d\n", count_tokens(pUser));
      //Adds user string to history list
      add_history(linkList,pUser);
      //tokenizes the input
      char **tokens = tokenize(pUser);
      print_tokens(tokens);
      free_tokens(tokens);
    }
    
  }
  done:
    return 0;
}
