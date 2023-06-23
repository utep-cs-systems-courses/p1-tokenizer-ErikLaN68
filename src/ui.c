#include "stdlib.h"
#include "stdio.h"
int myStrcmp (char*,char*);
//Need to re-order these but they are used in the main below. Could put into a include file
#define MAX 100
// \n is needed on these because fgets adds a \n to the user input when getting it.
char *pHis = "history\n";
char *pExit = "exit\n";

int main(int argc, char **argv)
{
  printf("The program name is <%s>\n", *(argv+0));
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

    // compares user input to "history" to view old inputs
    if (myStrcmp(pUser,pHis) == 0) {
	printf("will print history\n");
      }

    // compares user input to "exit" to leave the program
    else if (myStrcmp(pUser,pExit) == 0) {
      puts("Thanks for using the program");
      goto done;
      }
    
    else {
      puts("Will be tokenized");
    }
    
  }
  done:
    return 0;
}
