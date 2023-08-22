#include "shell.h"



/**
  *copyStr - copies one string to another string
  *@destination: string which is copied to
  *@source: String copies from
  *Return: pointer to the destination string
  */



char *copyStr(char *destination, char *source)
{
	int a = 0;

	for (; source[a] != '\0'; a++)
		destination[a] = source[a];
	destination[a] = '\0';
	return (destination);
}


