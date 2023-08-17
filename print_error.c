#include "shell.h"


/**
 * print_error - function that prints error to stdout in shell format
 * @command: command that caused the error
 * Return: 0 if succesful.
*/

int print_error(char *command)
{
	if (command != NULL)
	{
		write(1, shell_name, strlen(shell_name));
		write(1, ": ", 2);
		perror(command);
	}
	return (0);
}
