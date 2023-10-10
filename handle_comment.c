#include "shell.h"

/**
* handle_comment - handles the comment of user's input
* @str_input: the user's input
* Return: return input
*/

char *handle_comment(char *str_input)
{
	char *comment_out;

	if (str_input == NULL)
		return (NULL);
	comment_out = strchr(str_input, '#');
	if (comment_out != NULL)
		*comment_out = '\0';
	return (str_input);
}
