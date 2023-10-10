#include "shell.h"


/**
* _unsetenv - removes a environment variable
* @str_input: the user's input
* Return: returns 0 for success, -1 for failure
*/

int _unsetenv(char *str_input)
{
	char *temp, *name;
	int i;

	temp = _strtok(str_input, " ");
	name = _strtok(NULL, " ");
	if (name == NULL)
	{
		handle_msg(temp);
		return (-1);
	}
	i = 0;
	while (__environ[i] != NULL)
	{
		if (strncmp(__environ[i], name, (strlen(name) - 1)) == 0)
		{
			free(__environ[i]);
			removeMemoryRecord(__environ[i]);
			while (__environ[i + 1] != NULL)
			{
				__environ[i] = __environ[i + 1];
				i++;
			}
			__environ[i] = NULL;
		}
		i++;
	}
	return (0);
}
