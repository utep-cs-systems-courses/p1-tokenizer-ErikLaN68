#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  puts("Welcome to the Tokenizer");
  printf("The program name is <%s>\n", *(argv+0));
  while (1){
    
    for (char **p = &argv[1]; *p; p++)
      printf("%s ",*p);
    putchar('\n');
    break;
  }
  return 0;
}
