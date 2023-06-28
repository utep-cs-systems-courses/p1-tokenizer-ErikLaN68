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
    return (space_char(c));
  }
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while (space_char(*str) == 0) {
    str++;
  }
  if (*str == '\0') {
    return 0;
  }
  else {
    return str;
  }
}

/* Returns a pointer to the terminator char following *token */
char *token_terminator(char *token)
{
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
  char *start = token_start(str);
  char *end = token_terminator(start);
  while (*end != '\0') {
    counter++;
    start = token_start(end);
    end = token_terminator(start);
  }
  
  if (*end == '\0') counter++;
  
  return counter; 
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copy = (char*)malloc((len+1)*sizeof(char));
  char *p = copy;
  int i = 0;
  while (i<len) {
    *copy = *inStr;
    inStr++;
    copy++;
    i++;
  }
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
  char **topToken = tokens, *start = str;
  int i = 0;
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
  *tokens = '\0';
  //printf("%c\n",*tokens);
  //can change back to topToken if need
  return tokens - (wordCount);
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int count = 1;
  puts("---Tokens---");
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
  char **temp = tokens;
  while (*temp) {
    free(*temp);
    temp++;
  }
  free(tokens);
}
