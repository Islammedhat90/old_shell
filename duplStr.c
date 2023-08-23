#include "shell.h"

/**
 * duplStr -  Duplicates a string
 *@source: string to be duplicated
 * Return: returns a pointer to the new string
 */

char *duplStr(char *source)
{
	char  *duplicate;
	int length;

	length = lengthOfStr(source);

	duplicate = (char *)malloc(sizeof(char) * length + 1);

	if (duplicate == NULL)
		return ((char *)NULL);

	int i = 0;

	for (; source[i] != '\0'; i++)
		duplicate[i] = source[i];
	duplicate[i] = '\0';

	return (duplicate);

}

