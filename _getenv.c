#include "shell.h"

/**
 * _getenv - Returns a pointer to a env var value
 * @name: Environment variable name
 *
 * Return: Pointer to environment variable value
*/
char *_getenv(char *name)
{
	int i;

	for (i = 0; __environ[i] != NULL; i++)
		if (strncmp(__environ[i], name, strlen(name)) == 0)
			return (&__environ[i][strlen(name) + 1]);

	return (NULL);
}
