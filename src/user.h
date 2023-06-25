#ifndef USER_INCLUDED
#define USER_INCLUDED
#define MAX 100

int user_strcmp(char *a, char *b);
void user_remove_newline(char *str);

// \n is needed on these because fgets adds a \n to the user input when getting it.
char *pHis = "history";
char *pExit = "exit";

#endif
