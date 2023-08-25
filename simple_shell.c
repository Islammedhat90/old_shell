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
		printf("errno in begin  is %d\n", errno);
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
		printf("errno before operator check in is %d\n", errno);
		if (operatorcheck(handledline, count) != 0)
		{
			commands = com_arr(handledline, " \n\t\r");
			printf("errno before built in is %d\n", errno);
			b = handle_builtin(builtin_checker(commands[0]), commands);
			if (b == -1)
			{
				handle_path(commands, count);
				printf("errno after path handling is %d\n", errno);
			}
			else if (b == 0)
			{
				printf("errno before freeing %d\n", errno);
				free_arr(commands);
				break; }
			free_arr(commands); }
	}
	free(handledline);
	if (b == 0)
	{
		printf("errno roght before exit %d\n", errno);
		my_exit();
	}
	return (0); }
