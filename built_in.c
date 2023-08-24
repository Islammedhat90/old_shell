#include "shell.h"


/**
  * builtin_checker - function that checks if the command is built in.
  *@command: command to be checked.
  * Return: returns number if built in, -1 otherwise
  */

int builtin_checker(char *command)
{
	int i = 0;
	char *builtin[] = {"exit", "env", "cd", "setenv", "unsetenv"};

	if (command != NULL)
	{
		for (; i < 5; i++)
		{
			if (compStr(command, builtin[i]) == 0)
				return (i);
		}
		return (-1);
	}
	perror("NULL command");
	return (-1);
}

/**
 * handle_builtin - Handles built-in commands based on input code.
 * @m: The code representing the built-in command.
 * @commands: array of commands
 * Return: 0 if successful, -1 on error or unknown command.
 */

int handle_builtin(int m, char **commands)
{
	if (m == -1)
		return (-1);
	switch (m)
	{
		case 0:
			return (0);
		case 1:
			my_env();
			return (1);
		case 2:
			my_cd(commands);
			return (1);
		case 3:
			my_setenv(commands);
			return (1);
		default:
			return (-1);
	}
	return (0);
}

/**
  * my_exit - function that implements builtin exit.
  * @command: holds the exit status to print.
  * Return: nothing.
  */

void my_exit(char *command)
{
	if (command == NULL)
		exit(2);
}

/**
  * my_env - function that prints current environment
  *
  * Return: nothing.
  */

void my_env(void)
{
	char **env = environ;
	int i = 0;

	for (; env[i] != NULL; i++)
	{
		write(1, env[i], lengthOfStr(env[i]));
		write(1, "\n", 1);
	}
}

/**
 * my_cd - Change the current working directory.
 * @commands: An array of strings containing the command and arguments.
 * Return: nothing.
 */

void my_cd(char **commands)
{
	int check = -1;
	int count = command_count(commands);
	char *dir = NULL;

	__attribute__((unused))char *cur = _getenv("PWD");

	if (count > 2)
		print_error(commands[0]);
	else
	{
		if (commands[1] == NULL)
		{
			dir = _getenv("HOME");
		}
		else if (commands[1][0] == '-')
			dir = _getenv("OLDPWD");
		else
		{
			dir = strdup(commands[1]);
			check = 1;
		}
		if (chdir(dir) == 0)
			_setenv("PWD", dir);
		else
			perror("can't change directory");
	}
	if (check == 1)
		free(dir);
}



