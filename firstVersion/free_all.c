#include "shell.h"


/**
* free_all - frees the buffer
* @buffer: the buffer
*/

void free_all(char **buffer)
{
	int i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
	}
	free(buffer);
}
