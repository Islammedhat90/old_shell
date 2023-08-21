#include "shell.h"

char *shell_name = "./hsh";

/**
  * main - simple_shell initializztion.
  *@ac: argument counter.
  *@av: array of arguments.
  * Return: 0 if shell exits;
  */

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	char *line = NULL, **commands = NULL; char *handledline = NULL;
	char *prompt = "(OURSHELL) : ";
	size_t n;
	ssize_t read;
	int b = 0;

	while (1)
	{
		if (isatty(0))
			printf("%s", prompt);
		read = getline(&line, &n, stdin);
		if (read == -1)
			break;
		handledline = handle_line(line);
		if (handledline[0] == '\n')
			continue;
		commands = com_arr(line, " \n");
		b = handle_builtin(builtin_checker(commands[0]));
		if (b == -1)
			handle_path(commands);
		else if (b == 0)
		{
			free_arr(commands);
			break;
		}
		free_arr(commands);
	}
	free(handledline);
	if (b == 0)
	{
		printf("here");
		my_exit(NULL);
	}
	return (0);
}
