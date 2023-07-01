#include "stdio.h"
#include "stdlib.h"
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  //allocates memory of size List
  List *linkList = malloc(sizeof(List));
  //sets the root to NULL
  linkList->root = NULL;
  return linkList;
}

/* Find the length from the char pointer that is passed to it */
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
  //checks to see if the root of the list is empty
  if (list->root == NULL) {
    //allocates memory of size item
    Item *root = malloc(sizeof(Item));
    root->id = 1;
    //copies the given string into the new root
    root->str = copy_str(str,string_len(str));
    list->root = root;
    root->next = NULL;
  }
  //adds a node if the root is not null
  else {
    //pointer variable with pointer to root node
    //needed so the list doesn't write over it self
    Item *copyRoot = list->root;
    Item *newNode = malloc(sizeof(Item));
    //Finds the end of the list and adds a new node
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
  //runs through the list till the given number is found
  //if not then NULL is returned
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
  //Checks if the root is NULL
  if (list->root == NULL) {
    puts("History is empty");
  }
  else {
    //Runs through the whole list till the end printing the strings inside the nodes
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
  //checks that the current root has a next
  while (list->root->next) {
    //temp for next node of root
    Item *nextNode = list->root->next;
    //frees it
    free(list->root);
    //sets the root to the temp next node
    list->root = nextNode;
  }
  //need because the while misses the last node
  free(list->root);
  //frees the list
  free(list);
}
