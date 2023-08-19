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
	printf("path end");
	return (NULL);
}

void handle_path(char **commands)
{
	char *path = NULL;
	pid_t pid;

	if (commands != NULL)
	{
		if (*commands[0] == '/')
		{
			path = strdup(commands[0]);
			if (path == NULL)
			{
				perror("couldn't allocate memory");
				exit(EXIT_FAILURE);
			}
		}
		else
			path = get_path(commands[0]);
		printf("PATH is %s\n", path);
		if (path != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				if (exe_fun(path, commands, NULL) == -1)
				{
					exit(99);
				}
			}
			else if (pid > 0)
			{
				int status;

				wait(&status);
				free(path);
			}
			else
			{
				perror("fork failed");
				print_error(commands[0]);
			}
		}
		else
			print_error(commands[0]);
	}
	return;
}
