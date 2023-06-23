#include "stdlib.h"
#include "stdio.h"
int myStrcmp (char*,char*);

int main(int argc, char **argv)
{
  puts("Welcome to the Tokenizer");
  printf("The program name is <%s>\n\n", *(argv+0));
  while (1){
    fputs("Enter a string to be tokenized, enter history to see pervious inputs, or enter quit to leave the program\n> ",stdout);
    
    char userString[100];
    fgets(userString,sizeof(userString),stdin);
    printf("%s\n", userString);

    char *pUserString = userString;
    char *pHistory = "history";
    if (myStrcmp(pUserString,pHistory)) {
	printf("while print history");
      }
    
    break;
  }
  return 0;
}
