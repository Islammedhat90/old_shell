#include "shell.h"

/**
 * get_path - functions that returns path of a command
 * @command: command to get path for if it exists.
 * Return: absolute path for a command or NULL if not found
*/

char *get_path(char *command)
{
	char *path = NULL, *path_env = NULL, **paths = NULL;
	int i = 0;

	path_env = _getenv("PATH");
	paths = com_arr(path_env, ":");
	if (command != NULL)
	{
		for (; paths[i] != NULL; i++)
		{
			path = malloc(sizeof(char) * (lengthOfStr(paths[i]) +
						lengthOfStr(command) + 2));
			if (path == NULL)
			{
				perror("Couldn't allocate memory");
				free_arr(paths);
				exit(EXIT_FAILURE);
			}
			copyStr(path, paths[i]);
			appendStr(path, "/");
			appendStr(path, command);
			if (access(path, F_OK) == 0)
			{
				free_arr(paths);
				return (path);
			}
			free(path);
		}
	}
	free_arr(paths);
	return (NULL);
}

/**
  * handle_path - function that executes the command with path
  * @commands: double pointer holding all commands and arguments.
  * @count: second argument
  * Return: nothing.
  */

void handle_path(char **commands, int count)
{
	char *path = NULL;
	pid_t pid;

	if (commands != NULL)
	{
		if (*commands[0] == '/' || *commands[0] == '.')
		{
			path = duplStr(commands[0]);
			if (path == NULL)
			{
				perror("couldn't allocate memory");
				exit(EXIT_FAILURE);
			}
		}
		else
			path = get_path(commands[0]);
		if (path != NULL)
		{
			if (access(path, X_OK) == 0)
			{
				pid = fork();
				if (pid == 0)
					execve(path, commands, NULL);
				else if (pid > 0)
				{
					int status;

					wait(&status);
					if (WIFEXITED(status))
						errno = WEXITSTATUS(status);
					free(path); }
				else
				{
					perror("fork failed");
					free(path);
					print_error(commands[0]); }
			}
			else
			{
				print_commanderr(commands[0], count);
				errno = 127;
			}
		}
		else
		{
			print_commanderr(commands[0], count);
			errno = 127;
		}
	}
}
