#include <stdio.h>

/* Compares string s to string t and returns 0 if s==t, <0 s<t, or >0 s>t */
int user_strcmp (char *a, char *b)
{
  while (*a && *b) {/* until end of string */
    int diff = *a++ - *b++;
    if (diff) return diff;/* differed within string */
  }
  if (!*a && !*b) return 0;/* strings are same length & content */
  return (*a) ? 1 : -1;/* a > b if a is longer */
}

void user_remove_newline (char *str)
{
  while (*str != '\n') {
    str++;
  }
  *str = '\0';
}
