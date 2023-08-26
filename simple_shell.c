#include "shell.h"


/**
  * main - simple_shell initializztion.
  *@ac: argument counter.
  *@av: array of arguments.
  * Return: 0 if shell exits;
  */

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	char *line = NULL, **commands = NULL, *handledline = NULL;
	char *prompt = "(OURSHELL) : ";
	size_t n;
	ssize_t read;
	int b = 0, count = 0;

	while (1)
	{
		count++;
		if (isatty(0))
		{
			write(1, prompt, lengthOfStr(prompt));
			fflush(stdin); }
		signal(SIGINT, handle_ctrlc);
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			if (isatty(0) == 1)
				write(1, "\n", 1);
			free(line);
			exit(EXIT_SUCCESS); }
		if (line[0] == '\n' || (line_checker(line) == -1))
			continue;
		handledline = handle_line(line);
		if (operatorcheck(handledline, count) != 0)
		{
			commands = com_arr(handledline, " \n\t\r");
			b = builtin_checker(commands[0]);
			if (b == -1)
				handle_path(commands, count);
			else
			{
				free(handledline);
				handle_builtin(b, commands, count);
			}
			free_arr(commands); }
	}
	free(handledline);
	my_exit(commands, count);
	return (0); }
