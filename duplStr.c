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
	int i;

	length = lengthOfStr(source);

	duplicate = (char *)malloc(sizeof(char) * length + 1);

	if (duplicate == NULL)
		return ((char *)NULL);

	for (i = 0; source[i] != '\0'; i++)
		duplicate[i] = source[i];
	duplicate[i] = '\0';

	return (duplicate);

}

