#include "shell.h"

/**
* _getenv - gets the environment variable
* @var: the variable to grab
* Return: returns a pointer to the variable
*/

char *_getenv(char *var)
{
	int i;

	i = 0;
	while (__environ[i] != NULL)
	{
		if (strncmp(__environ[i], var, strlen(var)) == 0)
			return (&__environ[i][strlen(var) + 1]);
		i++;
	}
	return (NULL);
}
