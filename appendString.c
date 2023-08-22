#include "shell.h"


/**
*appendStr - concatenates one string to another string
*@destination:string which is copied to
*@source:String copies from
*Return: pointer to the destination string
*/

char *appendStr(char *destination, char *source)

{
	size_t a, b, c;

	a = lengthOfStr(source);

	b = lengthOfStr(destination);


	for (c = 0; c <= a; c++)
		destination[b + c] = source[c];

	return (destination);

}

