#include "stdio.h"
#include "stdlib.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' '||c == '\t') return 0;
  return 1;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if (c == '\0') {
    return 0;
  }
  else {
    //checks if c is a non-whitespace using space_char
    return (space_char(c));
  }
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  //if a space is found then the pointer keeps moving
  while (space_char(*str) == 0) {
    str++;
  }
  //checks if at end of string
  if (*str == '\0') {
    return 0;
  }
  //returns the pointer to the first character in the word
  else {
    return str;
  }
}

/* Returns a pointer to the terminator char following *token */
char *token_terminator(char *token)
{
  //increases the pointer as long as no space or \0 is seen
  //starts with the pointer of the word
  while (non_space_char(*token)) {
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  /* checks to see if the user input is empty */
  if (*str == '\0'||*str == '\t') return 0;
  
  int counter = 0;
  //finds the first word
  char *start = token_start(str);
  char *end = token_terminator(start);
  //runs till the end of a word is equal to \0
  while (*end != '\0') {
    counter++;
    start = token_start(end);
    end = token_terminator(start);
  }
  //increaes the counter when the last word is found
  if (*end == '\0') counter++;
  
  return counter; 
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  //allocates space for the string plus the \0
  char *copy = (char*)malloc((len+1)*sizeof(char));
  char *p = copy;
  int i = 0;
  //runs the length of the word
  while (i<len) {
    *copy = *inStr;
    inStr++;
    copy++;
    i++;
  }
  //loop does not add \0
  *copy = '\0';
  //This works
  //free(p);
  return p;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int wordCount = count_tokens(str);
  //printf("The word count plus 1 is %d\n",(wordCount+1));
  //Have to use sizeof(char *) to get the needed size of a pointer//
  char **tokens = (char **)malloc((wordCount+1)*sizeof(char *));
  char *start = str;
  int i = 0;
  //Runs throught all words
  while (i<wordCount) {
    start = token_start(start);
    char *pCopy = copy_str(start,token_terminator(start)-start);
    *tokens = pCopy;
    //printf("%s\n",*tokens);
    start = token_terminator(start);
    tokens++;
    i++;
  }
  //char *pterm = '\0';
  //printf("%d\n",i);
  //added to the end of the pointer array
  *tokens = '\0';
  //printf("%c\n",*tokens);
  //can change back to topToken if need
  return tokens - wordCount;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int count = 1;
  puts("---Tokens---");
  //runs till token is equal to \0
  while (*tokens) {
    printf("[%d]: %s\n",count,*tokens);
    tokens++;
    count++;
  }
  puts("------------");
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  //needed when running through the all the pointers
  char **temp = tokens;
  while (*temp) {
    free(*temp);
    temp++;
  }
  free(tokens);
}
