#include "shell.h"

/**
* test_alias - conditions for handling aliases
* @str_input:it the user's input
*/

void test_alias(char *str_input)
{
	char *com, *str, *temp;
	char *name, *value;

	com = _strtok(str_input, " ");
	str = _strtok(NULL, " ");
	if (str == NULL)
		print_all();
	else
	{
		temp = _strtok(str, "=");
		if (temp == NULL)
			print_alias(temp);
		else
		{
			name = temp;
			value = _strtok(NULL, " \n");
			if (value == NULL)
				print_alias(name);
			else
				addAlias(name, value);
		}
	}
	(void)com;
}
