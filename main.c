#include "shell.h"


/**
* main - Entry point for program
* @ac: the number of arguments
* @av: user's input from terminal
* Return: always 0
*/

int main(int ac, char **av)
{
	ssize_t line;
	int fd, exec_file = 0;
	char *buffer = NULL;
	size_t buff_size = 0;

	fd = handle_arguments(ac, av, &exec_file);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1 && exec_file == 0)
			write(STDOUT_FILENO, "$ ", 2);
		line = getline(&buffer, &buff_size, stdin);
		if (line == EOF || line == -1)
		{
			free(buffer);
			exit(98);
		}
		buffer = handle_comment(buffer);
		handle_semicolon(buffer);
	}
	free(buffer);
	if (exec_file)
		close(fd);
	return (0);
}
