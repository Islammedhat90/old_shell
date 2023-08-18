#include "shell.h"


/**
  * main - simple_shell initializztion.
  *@ac: argument counter.
  *@av: array of arguments.
  * Return: 0 if shell exits;
  */

int main(__attribute__((unused))int ac, char **av)
{
	char *line = NULL, **commands = NULL, *path = NULL;
	char *prompt = "(OURSHELL) : ";
	size_t n;
	ssize_t read;
	pid_t pid;

	__attribute__((unused))char *shell_name = strdup(av[0]);

	while (1)
	{
		printf("%s", prompt);
		read = getline(&line, &n, stdin);
		if (read == -1)
			break;
		commands = com_arr(line, " \n");
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
			}
		}
		else
			print_error(commands[0]);
	}
	free(line);
	free(shell_name);
	free_arr(commands);
	free(path);
	return (0);
}
