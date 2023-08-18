#include "shell.h"

/**
 * get_path - functions that returns path of a command
 * @dirs: directories to search for a command in.
 * Return: absolute path for a command or NULL if not found
*/

char *get_path(char *command)
{
	char *path = NULL, *path_env = NULL, **paths = NULL;
	int i = 0;;

	path_env = _getenv("PATH");
	paths = com_arr(path_env, ":\n");
	if (command != NULL)
	{
		if (command[0] == '/')
		{
			if (access(command, F_OK) == 0)
			{
				return (command);
			}
			return (NULL);
		}
		for (; paths[i] != NULL; i++)
		{
			path = malloc(sizeof(char) * (strlen(paths[i]) + strlen(command) + 2));
			if (path == NULL)
			{
				perror("Couldn't allocate memory");
				free_arr(paths);
				exit(EXIT_FAILURE);
			}
			strcpy(path, paths[i]);
			strcat(path, "/");
			strcat(path, command);
			if (access(path, F_OK) == 0)
			{
				free_arr(paths);
				return (path);
			}
			free(path);
		}
	}
	free_arr(paths);
	free(path);
	printf("get path end\n");
	return (NULL);
}

void handle_path(char **commands)
{
	char *path = NULL;
	pid_t pid;

	if (commands != NULL)
	{
		path = get_path(commands[0]);
		if (path != NULL)
		{
			pid = fork();
			if (pid == 0)
				exe_fun(path, commands, NULL);
			else if (pid > 0)
			{
				int status;

				wait(&status);
				free(path);
				return;
			}
			else
			{
				print_error(commands[0]);
				free(path);
			}
		}
		print_error(commands[0]);
		return;
	}
	return;
}
