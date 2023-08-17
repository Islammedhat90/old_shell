#include "shell.h"

/**
 * com_arr - funtion that returns an array
 *  with all commands and arguments.
 * @line: line with user input.
 * @delim: characters to split strings from.
 * Return: returns pointer to pointer with all commands.
*/

char **com_arr(char *line, char *delim)
{
	char *token = NULL, **commands = NULL, *linecopy = NULL;
	int command_count = 0, i = 0;

	if (delim == NULL)
		delim = " ";
	linecopy = strdup(line);
	token = strtok(linecopy, delim);
	while (token != NULL)
	{
		command_count++;
		token = strtok(linecopy, delim);
	}
	commands = malloc(sizeof(char *) * (command_count + 1));
	if (commands == NULL)
	{
		perror("Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	linecopy = strdup(line);
	token = strtok(linecopy, delim);
	for (i = 0; token != NULL; i++)
	{
		commands[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	free(linecopy);
	return (commands);
}

