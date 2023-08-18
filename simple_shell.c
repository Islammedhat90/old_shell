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
	int b = 0;

	__attribute__((unused))char *shell_name = strdup(av[0]);

	while (1)
	{
		printf("%s", prompt);
		read = getline(&line, &n, stdin);
		if (read == -1)
			break;
		if (line[0] == '\n')
			continue;
		commands = com_arr(line, " \n");
		b = handle_builtin(builtin_checker(commands[0]));
		if (b == -1)
			handle_path(commands);
		else if (b == 0)
			break;
		free_arr(commands);
	}
	free(line);
	free(shell_name);
	free_arr(commands);
	free(path);
	if (b == 0)
	{
		printf("here");
		my_exit(NULL);
	}
	return (0);
}
