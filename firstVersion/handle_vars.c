#include "shell.h"


static MemoryRecord *memoryList;


/**
* addMemoryRecord - adds data to linked list
* @data: the data to store
*/

void addMemoryRecord(char *data)
{
	MemoryRecord *record = malloc(sizeof(MemoryRecord));

	if (record != NULL)
	{
		record->data = data;
		record->next = memoryList;
		memoryList = record;
	}
}


/**
* removeMemoryRecord - removes data from linked list
* @data: the data to remove
*/

void removeMemoryRecord(char *data)
{
	MemoryRecord *current = memoryList;
	MemoryRecord *previous = NULL;

	while (current != NULL)
	{
		if (current->data == data)
		{
			if (previous == NULL)
				memoryList = current->next;
			else
				previous->next = current->next;
		}
		free(current);
		break;
	}
	previous = current;
	current = current->next;
}



/**
* freeAllMemory - frees the linked list after exit function
*/

void freeAllMemory(void)
{
	while (memoryList != NULL)
	{
		MemoryRecord *temp = memoryList;

		memoryList = memoryList->next;
		free(temp->data);
		free(temp);
	}
}
