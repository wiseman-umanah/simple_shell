#include "shell.h"

long int string_to_int(char *str_number)
{
    char *endptr;

    long int intValue = strtol(str_number, &endptr, 10);
    if (strlen(endptr) > 1)
        return (0);
    else
        return (intValue);
}