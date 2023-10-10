#include "shell.h"


/**
* handle_exit - handles the exit command
* @str_input: the exit status
*/

void handle_exit(char *str_input)
{
	char *com, *temp1;
	char msg[1000] = "Illegal number: ";
	long int i = 0;

	com = _strtok(str_input, " ");
	temp1 = _strtok(NULL, " ");
	freeAllMemory();
	if (temp1 == NULL)
	{
		free(str_input);
		exit(98);
	}
	else
	{
		i = string_to_int(temp1);
		if (i == 0)
		{
			custom_msg(com, strncat(msg, temp1, strlen(temp1)));
			return;
		}
		free(str_input);
		exit(i);
	}
}
