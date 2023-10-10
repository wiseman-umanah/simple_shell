#include "shell.h"


/**
* handle_semicolon - handles semicolon of user's input
* @str_input: the user's input
* Return: returns 0 if successful
*/

int *handle_semicolon(char *str_input)
{
	char *command = strtok(str_input, ";");

	while (command != NULL)
	{
		handle_and_or(command);
		command = strtok(NULL, ";");
	}
	return (0);
}


/**
* handle_and_or - handles semicolon of user's input
* @str_input: the user's input
* Return: returns 0 if successful
*/

int *handle_and_or(char *str_input)
{
	char *command = _strtok(str_input, "||&&");

	while (command != NULL)
	{
		handle_firstarg(command);
		command = _strtok(NULL, "||&&");
	}
	return (0);
}
