#include "shell.h"


static AliasRec *memoryalias;


/**
* addAlias - adds new alias to linked list
* @name: the name of the alias
* @value: the value (command)
*/

void addAlias(char *name, char *value)
{
	AliasRec *record = malloc(sizeof(AliasRec));

	if (record != NULL)
	{
		record->name = malloc(strlen(name) + 1);
		record->command = malloc(strlen(value) + 1);
		if (record->name == NULL || record->command == NULL)
			return;
		strcpy(record->name, name);
		strcpy(record->command, value);
		record->next = memoryalias;
		memoryalias = record;
	}
}


/**
* print_alias - print an alias based in the name
* @name: the name of the alias
* Return: returns nothing, this is to break out of the function
*/

void print_alias(char *name)
{
	AliasRec *current;
	unsigned long int i;

	current = memoryalias;
	while (current != NULL)
	{
		i = strlen(current->name);
		if (strncmp(current->name, name, i) == 0)
		{
			printf("%s='%s'\n", current->name, current->command);
			return;
		}
		current = current->next;
	}
	alias_msg(name, "not found\n");
}


/**
* print_all - print all aliases - name='value'
*/

void print_all(void)
{
	AliasRec *current;

	current = memoryalias;
	while (current != NULL)
	{
		printf("%s='%s'\n", current->name, current->command);
		current = current->next;
	}
}

/**
* freeAll - frees the linked list of the alias after exit function
*/

void freeAll(void)
{
	while (memoryalias != NULL)
	{
		AliasRec *temp = memoryalias;

		memoryalias = memoryalias->next;
		free(temp->name);
		free(temp->command);
		free(temp);
	}
}


/**
* handle_command - checks if command in alias based on the name
* @str: the user's input
* Return: returns nothing, this is to break out of the function
*/

void handle_command(char *str)
{
	AliasRec *current;

	current = memoryalias;
	while (current != NULL)
	{
		if (strncmp(str, current->name, (strlen(str) - 1)) == 0)
		{
			handle_firstarg(current->command);
			return;
		}
		current = current->next;
	}
	handle_firstarg(str);
}
