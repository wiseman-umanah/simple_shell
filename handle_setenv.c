#include "shell.h"

/**
* handle_action - properly create the environment variable
* @name: name of the environment variable
* @value: the value of the environment variable
* @i: position of the environment variable
*/

void handle_action(char *name, char *value, int i)
{
	strcpy(__environ[i], name);
	strcat(__environ[i], "=");
	strcat(__environ[i], value);
}


/**
* _setenv - function to set environment variable
* @str_input: the user's input
* Return: return -1 if failed, 0 if successful
*/

int _setenv(char *str_input)
{
	char *temp, *name, *value;
	int i, len;

	temp = _strtok(str_input, " ");
	name = _strtok(NULL, " ");
	value = _strtok(NULL, " ");
	i = 0;
	if (name == NULL || value == NULL)
	{
		handle_msg(temp);
		return (-1);
	}
	len = strlen(name) + strlen(value) - 2;
	while (__environ[i] != NULL)
	{
		if (strncmp(__environ[i], name, (strlen(name) - 1)) == 0)
		{
			free(__environ[i]);
			__environ[i] = malloc(sizeof(char) * len);
			handle_action(name, value, i);
			addMemoryRecord(__environ[i]);
			return (0);
		}
		i++;
	}
	__environ[i] = malloc(sizeof(char) * len);
	handle_action(name, value, i);
	__environ[i + 1] = NULL;
	addMemoryRecord(__environ[i]);
	return (0);
}
