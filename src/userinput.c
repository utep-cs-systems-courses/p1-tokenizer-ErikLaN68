/* WIll have all functions that are needed for the ui and userinput part of the program */

/* Copies the string in s to t */
void strcpy(char *s, char *t)
{
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

/* Compares string s to string t and returns 0 if s==t, <0 s<t, or >0 s>t */
int strcmp (char *s, char *t)
{
  while (*s == *t) {
    s++;
    t++;
    if (*s == '/0')
      return 0;
  }
  return *s - *t;
}
