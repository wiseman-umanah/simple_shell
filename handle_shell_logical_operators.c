#include "shell.h"

void handle_aliases(char **commands);
void handle_cmd_not_found(char *buff, char **cmds_list, char **commands,
	char *first_av);

/**
 * handling_semicolon_and_operators - Handle semicolon and logical op
 * @buff: first buffer that functions read
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * Return: 0 on success
*/
void handling_semicolon_and_operators(char *buff, int read, char *first_av)
{
	char **cmds_list = NULL;

	execute_commands(buff, cmds_list, buff, read, first_av);
}

/**
 * handling_or - Handle || logical part
 * @buff_semicolon: first buffer that functions read
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * Return: 0 on success
*/
void handling_or(char *buff_semicolon, int read, char *first_av)
{
	int i, flag, prev_flag = -1;
	char **cmds_list_2 = parse_user_input(buff_semicolon, "||");

	for (i = 0; cmds_list_2[i] != NULL; i++)
	{
		flag = handling_and(cmds_list_2[i], read, first_av, prev_flag);
		prev_flag = flag;
	}
	free_dbl_ptr(cmds_list_2);
}

/**
 * handling_and - Handle && logical part and executes inside of it
 * @buff_or: first buffer that functions read
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * @prev_flag: last flag of ||, it is important to print or not
 * Return: 0 on success
*/
int handling_and(char *buff_or, int read, char *first_av, int prev_flag)
{
	int j = 0, flag = 1;
	char **cmds_list_3 = parse_user_input(buff_or, "&&");

	if (prev_flag == 0)
	{
		j++;
		if (cmds_list_3[j] == NULL)
			return (-1);
	}

	for (; cmds_list_3[j] != NULL; j++)
	{
		flag = execute_commands(buff_or, cmds_list_3,
									cmds_list_3[j], read, first_av);
		prev_flag = flag;
	}
	free_dbl_ptr(cmds_list_3);
	return (flag);
}

/**
 * execute_commands - Fork and create commands, child process and executed
 * @buff: first buffer that function read
 * @cmds_list: List of commands
 * @cmd: Single command as a string
 * @read: return of read (open with getline)
 * @first_av: av[0]
 * Return: 0 on success
*/
int execute_commands(char *buff, char **cmds_list,
	char *cmd, int __attribute__((unused))read, char *first_av)
{
	char **commands;
	int child_pid, _err = 0, flag = 0, *status = process_exit_code();

	commands = parse_user_input(cmd, " ");
	handle_var_replacement(commands);
	handle_aliases(commands);
	if (handle_exit(buff, cmds_list, commands) == -1 ||
			handle_enter(commands) == 1	||
			handle_builtins(commands) == 1)
	{
		free_dbl_ptr(commands);
		return (-1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		free_allocs(buff, cmds_list, commands, F_BUFF | F_CMD_L | F_CMDS);
		dispatch_error(first_av);
	}
	else if (child_pid == 0)
	{
		_err = handle_PATH(commands);
		execve(commands[0], commands, __environ);
		if (_err != 0)
			handle_cmd_not_found(buff, cmds_list, commands, first_av);
		free_allocs(buff, cmds_list, commands, F_BUFF | F_CMD_L | F_CMDS);
		dispatch_error(first_av);
	}
	wait(status);
	*status = WEXITSTATUS(*status);
	if (*status == 2)
		set_process_exit_code(127);
	free_dbl_ptr(commands);
	return (flag);
}

/**
 * handle_cmd_not_found - Print a message to stderr
 * @buff: User's input
 * @cmds_list: Array of commands
 * @commands: Array of strings
 * @first_av: First argument passed to the executable
*/
void handle_cmd_not_found(char *buff, char **cmds_list, char **commands,
	char *first_av)
{
	set_process_exit_code(127);
	write(2, first_av, strlen(first_av));
	write(2, ": 1: ", 5);
	write(2, commands[0], strlen(commands[0]));
	write(2, ": not found\n", 12);
	free_allocs(buff, cmds_list, commands, F_BUFF | F_CMD_L | F_CMDS);
	exit(127);
}
