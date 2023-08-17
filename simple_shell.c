#include "shell.h"

char *shell_name;

/**
  * main - simple_shell initializztion.
  *@ac: argument counter.
  *@av: array of arguments.
  * Return: 0 if shell exits;
  */

int main(int ac, char **av)
{
	char *line = NULL, **commands = NULL, *path = NULL;
	char *prompt = "(OURSHELL) : ";
	size_t n;
	ssize_t read;
	pid_t pid;

	shell_name = strdup(av[0]);
	void(ac);
	while (1)
	{
		write(1, prompt, strlen(prompt));
		fflush(stdout);
		read = getline(&line, &n, stdin);
		line[strlen(line) - 1] = '\0';
		if (read == -1)
			break;
		{
			commands = com_arr(line, NULL);
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
	}
	free(shell_name);
	free(line);
	free(commands);
	free(path);
	return (0);
}
