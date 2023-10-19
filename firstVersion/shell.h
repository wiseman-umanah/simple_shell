#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
* struct memory - handles memory allocation for setenv()
* @data: the name=value
* @next: pointer to the next variable
* Description: This contains all the information of setenv
*/

typedef struct memory
{
	char *data;
	struct memory *next;
} MemoryRecord;


/**
* struct Alias - handles aliases created during program execution
* @name: the name of the alias
* @command: the command to perform
* @next: Pointer to next node
*/

typedef struct Alias
{
	char *name;
	char *command;
	struct Alias *next;
} AliasRec;

int isdelimiter(char c, char *delimiter);
char *_strtok(char *str, char *delimiter);
char *handle_comment(char *str_input);
void handle_firstarg(char *str_input);
void handle_exit(char *str_input);
void free_all(char **buffer);
int *handle_semicolon(char *str_input);
int *handle_and_or(char *str_input);
int handle_processes(char *command);
int _setenv(char *str_input);
void handle_msg(char *com);
void handle_action(char *name, char *value, int i);
int _unsetenv(char *str_input);
void addMemoryRecord(char *data);
void removeMemoryRecord(char *data);
void freeAllMemory(void);
char *_getenv(char *var);
int custom_cd(char *input);
void custom_msg(char *com, char *msg);
long int string_to_int(char *str_number);
int handle_arguments(int ac, char **av, int *exec_file);
void addAlias(char *name, char *value);
void print_alias(char *str_input);
void print_all(void);
void freeAll(void);
void handle_command(char *str);
void test_alias(char *str_input);
void alias_msg(char *value, char *msg);

#endif /*SHELL_H*/
