#include "shell.h"

/**
* handle_arguments - Check the number of arguments passed to main
* @ac: Number of arguments
* @av: Array of arguments as strings
* @exec_file: Integer used to check if user wants to exec commands from file
*
* Return: File descriptor to file
*/

int handle_arguments(int ac, char **av, int *exec_file)
{
	int fd = STDIN_FILENO;
	char *err_msg = "Error: more than one argument\n";

	if (ac > 2)
	{
		write(STDERR_FILENO, err_msg, strlen(err_msg));
		exit(1);
	}
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY | O_CREAT | O_EXCL | O_TRUNC);
		*exec_file = 1;
	}
	if (fd == -1)
	{
		perror(av[0]);
		exit(1);
	}

	return (fd);
}
