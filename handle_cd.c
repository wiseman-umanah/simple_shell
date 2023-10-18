#include "shell.h"


/**
* custom_cd - changes a directory of file
* @input: the buffer
* Return: return 0 in success, -1 for failure
*/

int custom_cd(char *input)
{
	 char *com = strtok(input, " \t\n");
	char *path = strtok(NULL, " \t\n");
	char current_dir[1024];

	if (path == NULL)
	{
		 const char *home_dir = getenv("HOME");

		path = (char *)home_dir;
	}
	else if (strcmp(path, "-") == 0)
	{
		 const char *prev_dir = getenv("OLDPWD");

		if (prev_dir == NULL)
		{
			fprintf(stderr, "OLDPWD not set\n");
			return (-1);
		}
		path = (char *)prev_dir;
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror(com);
		return (-1);
	}
	if (chdir(path) == -1)
	{
		perror(com);
		return (-1);
	}
	if (setenv("PWD", current_dir, 1) == -1)
	{
		 perror(com);
		return (-1);
	}
	return (0);
}
