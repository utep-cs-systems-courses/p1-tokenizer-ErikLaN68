#include "stdio.h"
#include "stdlib.h"
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *linkList = malloc(sizeof(List));
  linkList->root = NULL;
  return linkList;
}

/* Find the length from the char pointe that is passed to it */
int string_len(char *str)
{
  int i = 0;
  while (*str) {
    str++;
    i++;
  }
  return i;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  if (list->root == NULL) {
    Item *root = malloc(sizeof(Item));
    root->id = 1;
    root->str = copy_str(str,string_len(str));
    list->root = root;
    root->next = NULL;
  }
  else { 
    Item *copyRoot = list->root;
    Item *newNode = malloc(sizeof(Item));
    while (copyRoot->next != NULL) {
      copyRoot = copyRoot->next;
    }
    newNode->id = copyRoot->id+1;
    newNode->str = copy_str(str,string_len(str));
    newNode->next = NULL;
    copyRoot->next = newNode;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *copyList = list->root;
  while (copyList) {
    if (copyList->id == id) {
      return copyList->str;
    }
    copyList = copyList->next;
  }
  return NULL;
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  if (list->root == NULL) {
    puts("History is empty");
  }
  else {
    Item *copyList = list->root;
    puts("---Input History---");
    while (copyList) {
      printf("[%d]: %s\n",copyList->id,copyList->str);
      copyList = copyList->next;
    }
    puts("-------------------");
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  while (list->root->next) {
    Item *nextNode = list->root->next;
    free(list->root);
    list->root = nextNode;
  }
  free(list);
}
