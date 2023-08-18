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
	char *token = NULL, **commands = NULL, *linecopy = NULL, *copy = NULL;
	int command_count = 0, i = 0, j, len;

	len = strlen(line);
	linecopy = malloc(len + 1);
	if (linecopy == NULL)
	{
		perror("Couldn't allocate memory");
		return (NULL);
	}
	copy = malloc(len + 1);
	if (copy == NULL)
	{
		perror("Couldn't allocate memory");
		free(linecopy);
		return (NULL);
	}
	strcpy(linecopy, line);
	strcpy(copy, line);
	token = strtok(linecopy, delim);
	while (token != NULL)
	{
		command_count++;
		token = strtok(NULL, delim);
	}
	printf("commands number are %i\n", command_count);
	commands = malloc(sizeof(char *) * (command_count + 1));
	if (commands == NULL)
	{
		free(linecopy);
		perror("Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(copy, delim);
	for (i = 0; token != NULL; i++)
	{
		commands[i] = strdup(token);
		if (commands[i] == NULL)
		{
			for (j = i - 1; j >= 0; j--)
				free(commands[j]);
			free(linecopy);
			free(commands);
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	commands[command_count] = NULL;
	free(copy);
	free(linecopy);
	return (commands);
}
