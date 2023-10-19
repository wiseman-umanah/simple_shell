#include "shell.h"

/**
* handle_firstarg - checks for commands to handle
* @str_input: the user's input
*/

void handle_firstarg(char *str_input)
{
	if (strncmp(str_input, "exit", 4) == 0)
		handle_exit(str_input);
	else if (strncmp(str_input, "alias", 5) == 0)
		test_alias(str_input);
	else if (strncmp(str_input, "setenv", 6) == 0)
		_setenv(str_input);
	else if (strncmp(str_input, "unsetenv", 8) == 0)
		_unsetenv(str_input);
	else if (strncmp(str_input, "cd", 2) == 0)
		custom_cd(str_input);
	else
		handle_processes(str_input);
}
