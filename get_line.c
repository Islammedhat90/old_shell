int lineGet(char **ptrLine, FILE *lineIn)
{
	int a =0; /*i*/
	char b; /*/c*/
	int length = 128; /*bufflen*/
	char *lineBuf = malloc(sizeof(char) * length); /*buff*/
	char *bufTemp; /*tempbuff*/

	while (1)
	{
		if (a == length - 1)
		{
			bufTemp = malloc(sizeof(char) * length * 2);
			strncpy(bufTemp, lineBuf, length);
			free(lineBuf);
			lineBuf = bufTemp;
			bufTemp = NULL;
		       	length = length *2;
		}
		
		b = fgetc(lineIn);

                if(b == '\n' || b == EOF)
		{
			lineBuf[a] = '\0';
			break;
		}
		else if (b == '\b' && a > 0)
			a = a -2;
		else
			lineBuf[a] = b;
		a++;
	}

	*ptrLine = malloc(sizeof(char) * (a +1));
	strncpy(*ptrLine, lineBuf, a +1);
	free(lineBuf);

	return a;
}

