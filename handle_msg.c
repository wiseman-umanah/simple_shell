#include "shell.h"


/**
* handle_msg - handles general error message
* @com: the first command of the user
*/

void handle_msg(char *com)
{
	write(STDERR_FILENO, "/bin/sh: ", 10);
	write(STDERR_FILENO, com, strlen(com));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Action failed\n", 15);
}

/**
* custom_msg - prints custom message
* @com: the command which produces the error
* @msg: the message to print
*/

void custom_msg(char *com, char *msg)
{
	write(STDERR_FILENO, "/bin/sh: 1: ", 13);
	write(STDERR_FILENO, com, strlen(com));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, strlen(msg));
	/*write(STDERR_FILENO, "\n", 1);*/
}
