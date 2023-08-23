#include "shell.h"
/**
 * handle_line - Function handles the line that user enters
 * @line: Take the line from getline function
 * Return: The handled string without new line(\n)
*/
char *handle_line(char *line)
{
	int len, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	len = (int)lengthOfStr(line);
	if (len == 1 && line[0] == '\n')
	{
		return (line);
	}
	len = (int)lengthOfStr(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int line_checker(char *line)
{
	int i = 0;
	
	if (line != NULL)
	{
		for (; line[i] != '\0'; i++)
		{
			if (line[i] != ' ' && line[i] != '\n')
				return (1);
		}
	}
	return (-1);
}

