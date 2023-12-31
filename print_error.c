#include "shell.h"


/**
 * print_error - function that prints error to stdout in shell format
 * @command: command that caused the error
 * Return: 0 if succesful.
*/

int print_error(char *command, int count)
{
	char *number = print_number(count);
	if (command != NULL)
	{
		write(STDERR_FILENO, "./hsh", lengthOfStr("./hsh"));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, number, lengthOfStr(number));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "exit", lengthOfStr("exit"));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "Illegal number: ", lengthOfStr("Illegal number: "));
		write(STDERR_FILENO, command, lengthOfStr(command));
		write(STDERR_FILENO, "\n", 1);
	}
	free(number);
	return (0);
}


/**
 * print_commanderr - Prints a command error message to standard error.
 * @command: The command that triggered the error.
 * @count: The error count.
 */

void print_commanderr(char *command, int count)
{
	char *number = print_number(count);

	write(STDERR_FILENO, "./hsh", lengthOfStr("./hsh"));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, lengthOfStr(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, lengthOfStr(command));
	write(STDERR_FILENO, ": ", 2);
	write(2, "not found", lengthOfStr("not found"));
	write(2, "\n", 1);
	free(number);
}

/**
 * print_number - Convert an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the newly allocated string representation,
 *         or NULL if memory allocation fails.
 */

char *print_number(int n)
{
	int num_copy = n;
	int digit_count = 1;
	int length = 0;
	int i = 0;
	char *result;

	while (num_copy > 9)
	{
		num_copy /= 10;
		digit_count *= 10;
		length++;
	}
	length++;
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (NULL);
	for (; digit_count >= 1; digit_count /= 10)
		result[i++] = ((n / digit_count) % 10) + '0';
	result[length] = '\0';
	return (result);
}

/**
 * handle_ctrlc - Handles the SIGINT (Ctrl-C) signal
 * by printing a message and exiting.
 * @signum: The signal number (ignored, required for signal handler signature).
 */

void handle_ctrlc(__attribute__((unused))int signum)
{
	write(1, "\n", 1);
	write(1, "(OURHSHELL) : ", lengthOfStr("(OURHSHELL) : "));
}
