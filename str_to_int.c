#include "shell.h"

/**
* string_to_int - changes a string number to a long integer
* @str_number: the string to change to long int
* Return: returns the value on success, returns 0 on failure
* Description: This function returns 0 when the program fails
* This is because on exit function will make use of this function
* if exit status is a negative number, 0 is return
* A negative number cannot be returned by this function
*/

long int string_to_int(char *str_number)
{
	char *endptr;
	long int intValue = strtol(str_number, &endptr, 10);

	if (strlen(endptr) > 1)
		return (0);
	else
		return (intValue);
}
