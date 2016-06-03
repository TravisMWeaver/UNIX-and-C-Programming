#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LENGTH 128

typedef char String[STRING_LENGTH];

typedef int bool;
enum{false, true};

typedef enum
{
	mammal,
	insect,
	bird,
	fish
} AnimalClass;

typedef struct
{
	String name;
	double size;
	AnimalClass type;
} Animal;

AnimalClass inputAnimalClass(String type)
{
	if(!strcmp(type, "mammal"))
	{
		return (mammal);
	}

	else if(!strcmp(type, "insect"))
	{
		return (insect);
	}

	else if(!strcmp(type, "bird"))
	{
		return (bird);
	}

	else if(!strcmp(type, "fish"))
	{
		return (fish);
	}

	else
	{
		perror("ERROR: Animal type not found in database. Please try again.\n");
		return(EXIT_FAILURE);
	}
}

char *getAnimalClass(AnimalClass type)
{
	switch(type)
	{
		case mammal:
			return("mammal");

		case insect:
			return("insect");

		case bird:
			return("bird");

		case fish:
			return("fish");

		default:
			return("--- ERROR: Animal type not found in database. Please try again. ---");
	}
}

void printAnimalNameText(void)
{
	printf("Enter animal information (\"exit\" to exit)\n");
	printf("What is the name : ");
}

void getAnimalOutput(Animal * animalPointer, int index)
{
	int printIndex;

	printf("\nThe following new species were found: \n");

	for(printIndex = 0; printIndex < index; printIndex++)
	{
		printf("%-20s has size %5.2lf and is a %s\n", animalPointer[printIndex].name, animalPointer[printIndex].size, getAnimalClass(animalPointer[printIndex].type));
	}
}

int main(void)
{
	int arraySize = 1;
	int index = 0;
	Animal *animalPointer;
	Animal *expandAnimalPointer;

	animalPointer = malloc(sizeof(Animal));

	if(animalPointer == NULL)
	{
		perror("ERROR: Memory allocation failure.");
		return(EXIT_FAILURE);
	}

	String name;

	printAnimalNameText();
	scanf("%s", name);

	while(strcmp(name, "exit"))
	{
		if(arraySize <= index)
		{
			arraySize = arraySize * 2;
			expandAnimalPointer = realloc(animalPointer, arraySize * sizeof(Animal));

			if(expandAnimalPointer == NULL)
			{
				perror("ERROR: Memory allocation expansion failure.");
				return(EXIT_FAILURE);
			}

			else
			{
				animalPointer = expandAnimalPointer;
			}
		}

		strncpy(animalPointer[index].name, name, STRING_LENGTH);

		printf("What is the size : ");
		scanf("%lf", &animalPointer[index].size);

		String type;

		printf("What is the type : ");
		scanf("%s", type);
		animalPointer[index].type = inputAnimalClass(type);

		index++;
		printAnimalNameText();
		scanf("%s", name);
	}

	getAnimalOutput(animalPointer, index);

	return(EXIT_SUCCESS);
}