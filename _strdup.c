#include "shell.h"

/**
*_strdup - returns a pointer to a newly allocated space in memory
*@str: string to be duplicated
*Return: pointer to a new string which is a duplicate of the string str
*/
char *_strdup(char *str)
{
	char *c;
	int i = 0, size;

	if (str == NULL)
		return (NULL);
	size = lengthOfStr(str);
	c = (char *)malloc(size + 1);
	if (c == NULL)
		return (NULL);
	for (; i <= size; i++)
		c[i] = str[i];
	return (c);
}

/**
 * _strncmp - Compares two strings up to n bytes
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to compare
 *
 * Return: Negative if s1 is less than s2, positive if s1 is greater than s2,
 *         or 0 if s1 is equal to s2 up to n bytes.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;
	
	for (; i < n; i++)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			break;
	}
	return (0);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
