#include "shell.h"

/**
 * _getenv - function to get value of var from environment table
 * @var: variable to match value for.
 * Return: pointer to value of variable or NULL otherwise.
*/

char *_getenv(char *var)
{
	char **env = environ;
	int size = lengthOfStr(var);

	while (*env != NULL)
	{
		if (_strncmp(var, *env, size) == 0 && (*env)[size] == '=')
			return (&(*env)[size + 1]);
		env++;
	}
	return (NULL);
}

/**
 * _setenv - function that sets value for an environ
 * @var: variable to either set or create
 * @value: value of variable to be set.
 * Return: 0 if success.
 */

int _setenv(char *var, char *value)
{
	extern char **environ;
	char *new = NULL;
	int i = 0, flag = -1;
	size_t len = 0;

	if (var == NULL || value == NULL)
		return (-1);
	len = strlen(var);
	new = malloc(len + strlen(value) + 2);
	if (new == NULL)
	{
		perror("couldn't allocate memory");
		return (-1);
	}
	strcat(new, var);
	strcat(new, "=");
	strcat(new, value);
	while (environ[i] != NULL)
	{
		if (strncmp(var, environ[i], len) == 0)
		{

			environ[i] = new;
			flag = 1;
		}
		i++;
	}
	if (flag != 1)
		environ[i] = new;
	return (0);
}
int my_setenv(char **commands)
{
	int count, i = -1;

	count = command_count(commands);
	if (count != 3)
	{
		perror("wrong arguments");
		return (-1);
	}
	i = _setenv(commands[1], commands[2]);
	if (i == 0)
		return (0);
	else
		return (-1);
}