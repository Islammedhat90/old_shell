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
	int command_count = 0, i = 0, j;

	linecopy = strdup(line);
	if (linecopy == NULL)
	{
		free(line);
		perror("Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(linecopy, delim);
	while (token != NULL)
	{
		command_count++;
		token = strtok(NULL, delim);
	}
	commands = malloc(sizeof(char *) * (command_count + 1));
	if (commands == NULL)
	{
		free(linecopy);
		free(line);
		perror("Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	free(linecopy);
	linecopy = strdup(line);
	if (linecopy == NULL)
	{
		free(line);
		free(commands);
		perror("Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(linecopy, delim);
	for (i = 0; token != NULL; i++)
	{
		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			for (j = i - 1; j >= 0; j--)
				free(commands[j]);
			free(line);
			free(linecopy);
			free(commands);
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	commands[command_count] = NULL;
	printf("line in commands is %s\n", line);
	free(linecopy);
	return (commands);
}
