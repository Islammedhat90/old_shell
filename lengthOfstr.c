#include "shell.h"

/**
 * lengthOfStr -  counts the number of char in a string except the NULL char
 *@string: string to count
 * Return: the number of char in the string
 */


size_t lengthOfStr(const char *string)
{
	size_t length = 0;

	while (string[length] != '\0')
		length++;

	return (length);

}

