#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 1024

typedef char String[STRING_LENGTH];

int main(void)
{
	char c;
	String comments;

	while(fgets(comments, 256, stdin) != NULL)
	{
		do
		{
			c = fgetc(stdin);
		}

		while(c != '/');

		c = fgetc(stdin);

		if(c == '*')
		{
			c = fgetc(stdin);

			do
			{
				printf("%s", &c);
				c = fgetc(stdin);
			}

			while(c != '*');
			continue;
		}

		if(c == '/')
		{
			do
			{
				c = fgetc(stdin);
				printf("%s", &c);
			}

			while(c != '\n');
			continue;
		}
	}

	return(EXIT_SUCCESS);
}