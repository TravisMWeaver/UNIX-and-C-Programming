#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#define STRING_LENGTH 1024

typedef char String[STRING_LENGTH];

int getWordNum(char *sentence)
{
	int index = 0;
	char *word;
	char *backup;

	word = strtok_r(sentence, " ", &backup);

	while(word != NULL)
	{
		index++;
		word = strtok_r(NULL, " ", &backup);
	}

	return index;
}

int main(void)
{
	String input;
	String regular;

	char *sentence;
	char *backup;

	int index = 0;

	regex_t CompiledRegExp;

	printf("Please enter the string to analyse\n");

	while(fgets(input, STRING_LENGTH, stdin) != NULL)
	{
		sentence = strtok_r(input, ".?!", &backup);

		printf("Please enter the regular expression : ");
		scanf("%s", regular);

		while(sentence != NULL)
		{
			printf("%s\n", sentence);

			if (regcomp(&CompiledRegExp, regular, REG_EXTENDED) != 0) 
			{
        		perror("ERROR: The given regular expression is not valid.\n");
        		exit(EXIT_FAILURE);
    		}

			if (regexec(&CompiledRegExp, sentence, 0, NULL, 0) == 0) 
			{
        		printf("Yes\t");
    		} 

    		else 
    		{
        		printf("No\t");
    		}

    		index = getWordNum(sentence);
    		printf("%d words\n", index);

    		sentence = strtok_r(NULL, ".?!", &backup);
		}

		regfree(&CompiledRegExp);

		break;
	}

	return(EXIT_SUCCESS);
}