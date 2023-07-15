#ifndef SHELL_H
#define SHELL_H


#define TRUE 1
#define prompt "#cisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

int _putchar(char c);
int _puts(const char *);
int inte(int, char **);
int non_inte(int, char **);
void fatal(char *);
void type_prompt();
char *eof(char *);
char *_strcpy(char *, char *);
char *_strncat(char *, const char *, int);
size_t _strcspn(const char *, const char *);
size_t _strlen(char *);
size_t _argslen(char **);
int execute(char *, char **, char **);
char **get_tokens(char *);
void free_tokens(char **);
void *err_malloc(unsigned int);

#endif