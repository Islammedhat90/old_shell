#include "shell.h"

/**
 * exe_fun - function that executes commands with arguments
 * @path: string that contains command.
 * @commands: contains the rest of arguments.
 * @envp: array of pointers the represent environment variables.
 * Return: 0 if successful.
*/

int exe_fun(char *path, char **commands, char **envp)
{
	if (execve(path, commands, envp) == -1)
	{
		print_error(path);
		free(path);
		free_arr(commands);
		exit(errno);
	}
	return (0);
}
