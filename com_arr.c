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
	int command_count = 0, len;

	len = lengthOfStr(line);
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
	copyStr(linecopy, line);
	copyStr(copy, line);
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
		perror("Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}
	fill_array(commands, copy, delim);
	commands[command_count] = NULL;
	free(copy);
	free(linecopy);
	return (commands);
}


/**
  * fill_array - function that fills command array
  * @commands: commands array to be filled
  * @copy: copy of arguments to fill array with
  * @delim: delimiters to use
  * Return: nothing;
  */

void fill_array(char **commands, char *copy, char *delim)
{
	char *token = NULL;
	int i = 0;

	token = strtok(copy, delim);
	for (; token != NULL; i++)
	{
		commands[i] = _strdup(token);
		if (commands[i] == NULL)
		{
			free_arr(commands);
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
}

/**
  * command_count - function that counts commands
  * @commands: array of commands
  * Return: number of commands;
  */

int command_count(char **commands)
{
	int i = 0;

	if (commands != NULL)
	{
		while (commands[i] != NULL)
			i++;
		return (i);
	}
	return (-1);
}
