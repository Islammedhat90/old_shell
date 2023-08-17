#include "shell.h"

/**
 * get_path - functions that returns path of a command
 * @dirs: directories to search for a command in.
 * Return: absolute path for a command or NULL if not found
*/

char *get_path(char *command)
{
	char *path, *path_env, **paths;

	path_env = _getenv("PATH");
	paths = com_arr(path_env, ":");
	if (command != NULL && paths != NULL)
	{
		if (command[0] == '/')
		{
			if (access(command, X_OK) == 0)
				return (command);
			return (NULL);
		}
		while (*paths != NULL)
		{
			path = malloc(sizeof(char) * (strlen(*paths) + strlen(command) + 1));
			strcpy(path, *paths);
			strcat(path, "/");
			strcat(path, command);
			if (access(path, X_OK) == 0)
			{
				return (path);
			}
			paths++;
		}
	}
	return (NULL);
}
