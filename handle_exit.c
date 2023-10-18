#include "shell.h"


/**
* handle_exit - handles the exit command
* @str_input: the exit status of  the code
*/

void handle_exit(char *str_input)
{
	char *com, *temp1;
	char msg[1000];
	long int i = 0;

	com = _strtok(str_input, " ");
	temp1 = _strtok(NULL, " ");
	freeAllMemory();
	freeAll();
	if (temp1 == NULL)
	{
		free(str_input);
		exit(0);
	}
	else
	{
		i = string_to_int(temp1);
		if (i == 0)
		{
			strcpy(msg, "Illegal number: ");
			 custom_msg(com, msg);
			   free(str_input);
			    exit(1);
		}
		free(str_input);
		exit(i);
	}
}
