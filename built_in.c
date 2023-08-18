#include "shell.h"


/**
  * built_in - function that checks if the command is built in.
  *@command: command to be checked.
  * Returns: returns 1 if built in -1 otherwise 
  */

int builtin_checker(char *command)
{
	int i = 0;
	char *builtin[] = {"exit","env"};
	
	if (command != NULL)
	{
		for (; i < 2; i++)
		{
			if (strcmp(command, builtin[i]) == 0)
				return i;
		
		}
		return (-1);
	}
	perror("NULL command");
	return (-1);
}

int handle_builtin(int m)
{
	if (m == -1)
		return (-1);
	switch (m)
	{
		case 0:
			return (0);
		case 1:
			break;
		default:
			return(-1);
	}
	return (0);
}

/** my_exit - function that implements builtin exit.
  * 
  * Return: nothing.
  */

void my_exit(char *command)
{
	if (command == NULL)
		exit(0);
}











