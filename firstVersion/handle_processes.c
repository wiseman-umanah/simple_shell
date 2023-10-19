#include "shell.h"

/**
* handle_processes - handles semicolon of user's input
* @command: the user's input
* Return: returns 0 if successful
*/

int handle_processes(char *command)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		execlp("/bin/sh", "/bin/sh", "-c", command, NULL);
		perror("exec failed");
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		perror("fork failed");
	return (0);
}
