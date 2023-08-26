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

/**
 * _isdigit - Check if a string  is all digits (0-9)
 * @c: The character to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char *number)
{
	int i = 0;

	for (; number[i] != '\0'; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return (-1);
	}
	return (0);
}

int my_atoi(char *str) 
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}









