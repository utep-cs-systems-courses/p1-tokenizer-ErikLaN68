Project 1: Tokenizer
====================
# Instructions and Information

## How to Run
 - Type "Make" to make the complied file called tokenshell
 - Type "Make run" for the complied file"
 - If needed type "Make clean" to remove tokenshell

## ui.c
 - This file is the engine of the program takes care of tokenizing and keeping
track of history.
 - Is able to take the commands "history" which shows the input history,
 "!(history id") which takes older input and tokenizes it, and "exit" which ends the program.

## userinput.c and user.h
 - userinput.c contains string functions that are needed to modify the user
 input string to work with tokenizer and !(history id).
 - user.h contains all declaration functions and other variables needed in the ui.c

## tokenizer.c and tokenizer.h
 - tokenizer.c has all the functions need to tokenize the user input and some
 of the functions are used in userinput.c and history.c.
 - tokenizer.h has all function declaratiosn for tokenizer.c

## history.c and history.h
 - history.c has all functions for the linked list and the function that finds
 a the string of the id that is given by !(history id).
 - history.h has all function declarations for history.h
