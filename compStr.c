#include "shell.h"

/**
 * compStr - compares two strings
 *@string1: pointer to first string
 *@string2: pointer to second string
 *Return: an integer
 */


int compStr(const char *string1, const char *string2)
{
	int a;
	int b;

	for (a = 0; string1[a] == string2[a] &&
			string1[a] != '\0' &&
			string2[a] != '\0';)
		a++;
	if (string1[a] == '\0' && string2[a] == '\0')
		b = 0;
	else
		b = 1;

	return (b);
}

